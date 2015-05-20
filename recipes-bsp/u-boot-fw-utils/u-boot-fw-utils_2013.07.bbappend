# This add the files present in "files" folder present in this path , inside the package "global files"
# if the file just exist in the package source , replace it , instead the file must added with search URI

FILESEXTRAPATHS_prepend := "${THISDIR}/files:"  

# use the added files as a normal recipe file

SRC_URI_append_mx6 = " file://add-imx6dl-support.patch "


do_install_append_mx6 () {

  install -d ${D}/${sysconfdir}
}


