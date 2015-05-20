fw_printenv > parametri.txt
cat parametri.txt | sed -e 's/=/ /' > env_backup.txt
rm parametri.txt
sync
echo "Backup u-boot parameter on env_backup.txt"
echo "for to write parameter use the command:"
echo "     fw_setenv -s env_backup.txt"
