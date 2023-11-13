from ftplib import FTP
import os

# Define FTP server details
server = 'nadinmeowmeow.freevar.com'
username = 'nadinmeowmeow.freevar.com'
password = ''  # Replace with your FTP password

# Login to the FTP server
ftp = FTP(server)
ftp.login(user=username, passwd=password)

# Change to the directory where the file is located
ftp.cwd('uploads')

# Define the remote and local file paths
remote_filename = 'ACC_FOTA_BREAKING_.hex'
local_path = '/home/pi/newdir/' + remote_filename  # Adjust the local path for Raspberry Pi

# Download the file
with open(local_path, 'wb') as local_file:
    ftp.retrbinary('RETR ' + remote_filename, local_file.write)

# Close the FTP connection
ftp.quit()


