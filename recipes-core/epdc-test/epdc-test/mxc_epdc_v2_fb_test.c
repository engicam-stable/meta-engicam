/*=======================================================================
					INCLUDE FILES
=======================================================================*/
/* Standard Include Files */
#define _GNU_SOURCE
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <linux/mxcfb.h>
#include <sys/mman.h>
#include <math.h>
#include <string.h>
#include <malloc.h>
#include <getopt.h>
#include <signal.h>

#include <string.h>
#include <unistd.h>
#include <time.h>

#define TFAIL -1
#define TPASS 0

#define TRUE 1
#define FALSE 0

#define BUFFER_FB		0
#define BUFFER_OVERLAY		1

#define WAVEFORM_MODE_INIT	0x0	/* Screen goes to white (clears) */
#define WAVEFORM_MODE_DU	0x1	/* Grey->white/grey->black */
#define WAVEFORM_MODE_GC16	0x2	/* High fidelity (flashing) */
#define WAVEFORM_MODE_GL16	0x3	/* High fidelity (no flashing) */
#define WAVEFORM_MODE_A2	0x6	/* Fast black/white animation */
#define WAVEFORM_MODE_DU4	0x7

#define EPDC_STR_ID		"mxc_epdc_fb"

#define  ALIGN_PIXEL_128(x)  ((x+ 127) & ~127)

#define CROSSHATCH_ALTERNATING  0
#define CROSSHATCH_COLUMNS_ROWS 1

#define ALLOW_COLLISIONS	0
#define NO_COLLISIONS		1

#define NUM_TESTS		21

#define ARRAY_SIZE(x)	(sizeof(x)/sizeof(x[0]))

#define USBDIR "/mnt/usbdisk"
#define DEFDIR "/usr/share/engicam"
#define SIZE 512
#define PNG_CODEC "png"
#define JPG_CODEC "jpegls"
#define JPG_BMP "bmp"

#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 1200

#define FILE_RAW "/mnt/ramdisk/image.raw"
//#define FILE_TEMP "/mnt/ramdisk/image.tmp"

__u32 pwrdown_delay = 0;
__u32 scheme = UPDATE_SCHEME_QUEUE_AND_MERGE;

int fd_fb;
int fd_fb_ioctl;
unsigned short * fb;
int g_fb_size;
struct fb_var_screeninfo screen_info;
__u32 marker_val = 1;
//static char has_usb = 0;
static char first_image = 1;

static void copy_image_to_buffer(int left, int top, int width, int height, uint *img_ptr, 	uint target_buf, struct fb_var_screeninfo *screen_info)
{
	int i;
	uint *fb_ptr;

	if (target_buf == BUFFER_FB)
		fb_ptr =  (uint *)fb;
	else if (target_buf == BUFFER_OVERLAY)
		fb_ptr = (uint *)fb +
			(screen_info->xres_virtual * ALIGN_PIXEL_128(screen_info->yres) *
			screen_info->bits_per_pixel/8)/4;
	else {
		printf("Invalid target buffer specified!\n");
		return;
	}

	if ((width > screen_info->xres) || (height > screen_info->yres)) {
		printf("Bad image dimensions!\n");
		return;
	}

	for (i = 0; i < height; i++)
		memcpy(fb_ptr + ((i + top) * screen_info->xres_virtual + left) * 2 / 4, img_ptr + (i * width) * 2 /4, width * 2);
}


static __u32 full_update_to_display(int wave_mode, int wait_for_complete, uint flags)
{
	struct mxcfb_update_data upd_data;
	struct mxcfb_update_marker_data upd_marker_data;
	int retval;
	int wait = wait_for_complete | (flags & EPDC_FLAG_TEST_COLLISION);
	int max_retry = 10;

	upd_data.update_mode = UPDATE_MODE_FULL;
	upd_data.waveform_mode = wave_mode;
	upd_data.update_region.left = 0;
	upd_data.update_region.width = screen_info.xres;
	upd_data.update_region.top = 0;
	upd_data.update_region.height = screen_info.yres;
	upd_data.temp = TEMP_USE_AMBIENT;
	upd_data.flags = flags;

	if (wait)
		/* Get unique marker value */
		upd_data.update_marker = marker_val++;
	else
		upd_data.update_marker = 0;

	retval = ioctl(fd_fb_ioctl, MXCFB_SEND_UPDATE, &upd_data);
	while (retval < 0) {
		/* We have limited memory available for updates, so wait and
		 * then try again after some updates have completed */
		sleep(1);
		retval = ioctl(fd_fb_ioctl, MXCFB_SEND_UPDATE, &upd_data);
		if (--max_retry <= 0) {
			printf("Max retries exceeded\n");
			wait = 0;
			flags = 0;
			break;
		}
	}

	if (wait) {
		upd_marker_data.update_marker = upd_data.update_marker;

		/* Wait for update to complete */
		retval = ioctl(fd_fb_ioctl, MXCFB_WAIT_FOR_UPDATE_COMPLETE, &upd_marker_data);
		if (retval < 0) {
			printf("Wait for update complete failed.  Error = 0x%x", retval);
			flags = 0;
		}
	}

	return upd_data.waveform_mode;
}


//#define FILE_GRAY "/mnt/ramdisk/image.gray"
static int show_image(unsigned int width, unsigned int height)
{
int retval = TPASS;
uint *imgptr = NULL;
FILE *fp;

  memset(fb, 0x0, screen_info.xres_virtual*screen_info.yres*screen_info.bits_per_pixel/8);
//  full_update_to_display(WAVEFORM_MODE_DU, FALSE, 0);   
  
  imgptr = malloc(width*height*2);
  fp = fopen(FILE_RAW, "r");
  if (fp)
  {
  unsigned int x_pos = 0, y_pos = 0;
  
    fread(imgptr, width*height*2, 1, fp);
    
    if (width < SCREEN_WIDTH)
    {
      x_pos = (SCREEN_WIDTH - width) / 2.0;
    }

    if (height < SCREEN_HEIGHT)
    {
      y_pos = (SCREEN_HEIGHT - height) / 2.0;
    }
    
    copy_image_to_buffer(x_pos, y_pos, width, height, imgptr, BUFFER_FB, &screen_info);    
  }
  else
  {
    puts("ERRORE: Lettura raw");    
  } 
  
  fclose(fp);

  // TEST
  full_update_to_display(WAVEFORM_MODE_GL16, FALSE, 0);    

  free(imgptr);

  printf("done\n");

	return retval;
}

#define IS_JPEG 1
#define IS_PNG  2
#define IS_BMP  3
static int convert_image(char *folder, char *filename, unsigned int *width_img, unsigned int *height_img)
{
int retval = TPASS;
FILE *pp;
char dummy[SIZE];
char image_type[8];
char tipo = 0;
int width = 0;
int height = 0;

  printf("Analisi %s/%s\n", folder, filename);

  sprintf(dummy, "/usr/bin/file -b '%s/%s'", folder, filename);
  puts(dummy);
  pp = popen(dummy, "r");
  if (pp)
  {
    if (fgets(dummy, SIZE, pp))
    {
    char *dummy_str;
    
      // Recupero dimensioni
      dummy_str = strtok(dummy, ",");
      if (dummy_str)
      {
        if (strcasestr(dummy_str, "bitmap"))
        {
          printf("Immagine BMP: ");
          strcpy(image_type, JPG_BMP);
          tipo = IS_BMP;
        }
        else if (strcasestr(dummy_str, "PNG"))
        {
          printf("Immagine PNG: ");
          strcpy(image_type, PNG_CODEC);
          tipo = IS_PNG;
        }
        else if (strcasestr(dummy_str, "JPEG"))
        {
          printf("Immagine JPEG: ");
          strcpy(image_type, JPG_CODEC);
          tipo = IS_JPEG;
        }        
        else
        {
          printf("Tipo file <%s> NON gestito\n", dummy_str);          
          return TFAIL;
        }
      }
      else
      {
        puts("ERRORE: Recupero tipo (1)");
        return TFAIL;
      }
      
      // Recupero le dimensioni
      switch (tipo)
      {
        case IS_BMP: // 327 x 148 x 32
          {
            strtok(NULL, ",");
            dummy_str = strtok(NULL, ",");  
          }
          break;

        case IS_JPEG:
          {
          char find_size = 0;
          
            while ((dummy_str = strtok(NULL, ",")))
            {
              if (strcasestr(dummy_str, "precision"))
              {
                find_size = 1;
                break;
              }
            }
            
            if (find_size)
            {
              dummy_str = strtok(NULL, ",");
            }
          }
          break;          
          
        case IS_PNG: 
          {
            dummy_str = strtok(NULL, ","); // 327 x 148
          }
          break;                    
      }
      
      if (dummy_str)        
      {
      char *str_width, *str_height;
      char size_image[SIZE];
      
        strcpy(size_image, dummy_str);
        str_width = strtok(size_image, "x");
        str_height = strtok(NULL, "x");
        if (str_width && str_height)
        {
          width = atoi(str_width);
          height = atoi(str_height);
          printf("Size immagine: %dx%d\n", width, height); 
        }
        else
        {        
          puts("ERRORE: Recupero size (2)");
          return TFAIL;
        }        
      }
      else
      {        
        puts("ERRORE: Recupero size (2)");
        return TFAIL;
      }
    }
    else
    {
      puts("ERRORE: Recupero tipo (2)");
      return TFAIL;
    } 
    
    pclose(pp);
  }
  else
  {
    puts("ERRORE: Recupero tipo (3)");
    return TFAIL;
  }
  
  unlink(FILE_RAW);
  //unlink(FILE_GRAY);
  if ((width >= SCREEN_WIDTH) || (height >= SCREEN_HEIGHT))
  {
    if ( (width >= SCREEN_WIDTH) && (height >= SCREEN_HEIGHT) )
    {
      width = SCREEN_WIDTH;
      height = -1;
    }
    else if (width >= SCREEN_WIDTH)
    {
      width = SCREEN_WIDTH;
      height = -1;
    }
    else
    {
      height = SCREEN_HEIGHT;
      width = -1;
    }
  }

  // Conversione scala di grigi
  sprintf(dummy, "/usr/bin/ffmpeg -y -vcodec %s -i '%s/%s' -vcodec rawvideo -f rawvideo -pix_fmt rgb565 -vf \"scale=%d:%d\" %s  2>&1 | grep 'Stream #0:0: Video: rawvideo'| cut -d ',' -f 3 | cut -d ' ' -f 2", image_type, folder, filename, width, height, FILE_RAW);
  pp = popen(dummy, "r");
  if (pp)
  {
  char ffmpeg_buff[SIZE];
    
    if (height == -1 || width == -1) // Recupero le nuove dimensioni
    {
      fgets(ffmpeg_buff, SIZE, pp);
      width = atoi(strtok(ffmpeg_buff, "x"));
      height = atoi(strtok(NULL, "x"));
    }
    
    pclose(pp);    
  }
  else
  {
    puts("ERRORE: Conversione GRAY");
    return TFAIL;
  } 
  
  // Conversione RAW
 /* sprintf(dummy, "/usr/bin/ffmpeg -y -vcodec rawvideo -f rawvideo -pix_fmt gray -s %dx%d -i %s -vcodec rawvideo -f rawvideo -pix_fmt rgb565 -s %dx%d %s", width, height, FILE_GRAY, width, height, FILE_RAW);
  pp = popen(dummy, "r");
  if (pp)
  {
  char ffmpeg_buff[SIZE];
    
    pclose(pp);    
  }
  else
  {
    puts("ERRORE: Conversione RAW");
    return TFAIL;
  }  */
  *width_img = width;
  *height_img = height;
 
  return TPASS;
}

#define SLEEP_TIME 5
static void retrieve_images()
{
struct dirent **namelist;
int n;
char dummy[SIZE];

  while (1)
  {
  char *folder = USBDIR;
  
    struct stat sb;
    if (stat(folder, &sb) != 0 || !S_ISDIR(sb.st_mode))
    {
      puts("Nessuna usb montata -> immagini di default");
      folder = DEFDIR;
    }

    puts("Scansione immagini");
    n = scandir(folder, &namelist, NULL, alphasort);  
    if (n < 0)
    {
      perror("scandir");
      
      break;
    }
    
    while (n--) 
    {
      if (strcmp(namelist[n]->d_name, ".") && strcmp(namelist[n]->d_name, ".."))
      {
      time_t start = time(NULL);
      unsigned int width, height;
      static char last_image[SIZE];
      
        if (strcmp(namelist[n]->d_name, last_image)) // Nuova immagine
        {
          // Copio
        /*  printf("Immagine: %s\n",  namelist[n]->d_name);
          sprintf(dummy, "cp -f '%s/%s' %s",folder, namelist[n]->d_name, FILE_TEMP);
          system(dummy);*/
          
          if (convert_image(folder, namelist[n]->d_name, &width, &height) == TPASS)
          {
          int remtime = SLEEP_TIME - (time(NULL)-start);
          
            if (remtime > 0 && first_image == 0)
            {
              printf("Ancora %d secs\n", remtime);
              sleep(remtime);
            }
            
            if (show_image(width, height) != TPASS)
            {
              puts("ERRORE: Renderizzazione immagine");
            }
            else
            {
              strcpy(last_image, namelist[n]->d_name);
              first_image = 0;
            }
          }
          else
          {
            printf("ERRORE: Conversione %s\n", namelist[n]->d_name);
            sleep(0.1);    
          }
         // unlink(FILE_TEMP);
        }
      }
      free(namelist[n]);
    }
    free(namelist);
    
    sleep(1);
  }
}

/*void sig_handler(int signo)
{
  if (signo == SIGUSR1) // Usb inserita -> blanko lo schermo
  {
    puts("Inserita USB");
    has_usb = 1;
    
   // memset(fb, 0xff, screen_info.xres_virtual*screen_info.yres*screen_info.bits_per_pixel/8);
   // full_update_to_display(WAVEFORM_MODE_INIT, TRUE, 0);
  }
  else if (signo == SIGUSR2) // Usb tolta
  {
    puts("Tolta USB");
    has_usb = 0;
    first_image = 1;
    
    // Carico il default
    system("cp -f /usr/share/engicam/default.raw /mnt/ramdisk/image.raw");
    show_image(SCREEN_WIDTH, SCREEN_HEIGHT);
  }
}*/

int main(int argc, char **argv)
{
int retval = TPASS;
int auto_update_mode;
struct mxcfb_waveform_modes wv_modes;
char fb_dev[10] = "/dev/fb0";
int fb_num = 0;
struct fb_fix_screeninfo screen_info_fix;
int i, rt;


	/* Find EPDC FB device */
  fd_fb = open(fb_dev, O_RDWR, 0);
  if (fd_fb < 0) 
  {
    printf("Unable to open %s\n", fb_dev);
    retval = TFAIL;
    goto err0;
  }

  /* Check that fb device is EPDC */
  /* First get screen_info */
  retval = ioctl(fd_fb, FBIOGET_FSCREENINFO, &screen_info_fix);
  if (retval < 0)
  {
    printf("Unable to read fixed screeninfo for %s\n", fb_dev);
    goto err1;
  }

  /* If we found EPDC, exit loop */
  if (!strcmp(EPDC_STR_ID, screen_info_fix.id)) 
  {
    printf("Opened EPDC fb device %s\n", fb_dev);
  }

	/*
	 * If kernel test driver exists, we default
	 * to using it for EPDC ioctls
	 */
	fd_fb_ioctl = open("/dev/epdc_test", O_RDWR, 0);
	if (fd_fb_ioctl >= 0)
  {
		printf("\n****Using EPDC kernel module test driver!****\n\n");
  }
	else
  {
		fd_fb_ioctl = fd_fb;
  }
  
	retval = ioctl(fd_fb, FBIOGET_VSCREENINFO, &screen_info);
	if (retval < 0)
	{
		goto err1;
	}
	
	printf("Set the background to 16-bpp\n");
	screen_info.bits_per_pixel = 16;
	screen_info.grayscale = 0;
	screen_info.yoffset = 0;
	screen_info.rotate = FB_ROTATE_UR;
	screen_info.activate = FB_ACTIVATE_FORCE;
  screen_info.yres_virtual = 1200;
	retval = ioctl(fd_fb, FBIOPUT_VSCREENINFO, &screen_info);
	if (retval < 0)
	{
		goto err1;
	}
	
	g_fb_size = screen_info.xres_virtual * screen_info.yres_virtual * screen_info.bits_per_pixel / 8;

	printf("screen_info.xres_virtual = %d\nscreen_info.yres_virtual = %d\nscreen_info.bits_per_pixel = %d\n", screen_info.xres_virtual, screen_info.yres_virtual, screen_info.bits_per_pixel);

	printf("Mem-Mapping FB\n");

	/* Map the device to memory*/
	fb = (unsigned short *)mmap(0, g_fb_size,PROT_READ | PROT_WRITE, MAP_SHARED, fd_fb, 0);
	if ((int)fb <= 0)
	{
		printf("\nError: failed to map framebuffer device 0 to memory.\n");
		goto err1;
	}

	printf("Set to region update mode\n");
	auto_update_mode = AUTO_UPDATE_MODE_REGION_MODE;
	retval = ioctl(fd_fb_ioctl, MXCFB_SET_AUTO_UPDATE_MODE, &auto_update_mode);
	if (retval < 0)
	{
		printf("\nError: failed to set update mode.\n");
		goto err2;
	}

	printf("Set waveform modes\n");
	wv_modes.mode_init = WAVEFORM_MODE_INIT;
	wv_modes.mode_du = WAVEFORM_MODE_DU;
	wv_modes.mode_gc4 = WAVEFORM_MODE_GC16;
	wv_modes.mode_gc8 = WAVEFORM_MODE_GC16;
	wv_modes.mode_gc16 = WAVEFORM_MODE_GC16;
	wv_modes.mode_gc32 = WAVEFORM_MODE_GC16;
	retval = ioctl(fd_fb_ioctl, MXCFB_SET_WAVEFORM_MODES, &wv_modes);
	if (retval < 0)
	{
		printf("\nError: failed to set waveform mode.\n");
		goto err2;
	}

	printf("Set update scheme - %d\n", scheme);
	retval = ioctl(fd_fb_ioctl, MXCFB_SET_UPDATE_SCHEME, &scheme);
	if (retval < 0)
	{
		printf("\nError: failed to set update scheme.\n");
		goto err2;
	}

	printf("Set pwrdown_delay - %d\n", pwrdown_delay);
	retval = ioctl(fd_fb_ioctl, MXCFB_SET_PWRDOWN_DELAY, &pwrdown_delay);
	if (retval < 0)
	{
		printf("\nError: failed to set power down delay.\n");
		goto err2;
	}

/*	signal(SIGUSR1, sig_handler);
  signal(SIGUSR2, sig_handler);
  
  // Carico il default
  system("cp -f /usr/share/engicam/default.raw /mnt/ramdisk/image.raw");
  show_image(SCREEN_WIDTH, SCREEN_HEIGHT);*/
  
  // Start
  retrieve_images();
  
err2:
	munmap(fb, g_fb_size);
err1:
	close(fd_fb);
	if (fd_fb != fd_fb_ioctl)
		close(fd_fb_ioctl);
err0:
	return retval;
}
