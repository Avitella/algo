echo " " &&
echo "This script will attempt to install Linux Kernel 3.10 on this machine." &&
echo "Typically, your current version will be kept, and you will be able to ustilise it again later if Kernel 3.10 does not work." &&
echo " " &&
read -p "Press Enter to continue, or abort by pressing CTRL+C" nothing &&
echo " " &&
echo "Downloading Kernel 3.10 Packages" &&
echo "3 Files, 57 MB to Download" &&
echo " " &&
echo "Creating Kernel Directory in Home folder" &&
echo " " &&
mkdir -p $HOME/kernel-htu &&
cd $HOME/kernel-htu &&
echo " " &&
echo "Downloading File 1 of 3, 12 MB" &&
echo " " &&
wget http://kernel.ubuntu.com/~kernel-ppa/mainline/v3.10.6-saucy/linux-headers-3.10.6-031006_3.10.6-031006.201308112316_all.deb &&
echo " " &&
if [ $(getconf LONG_BIT) = "64" ]
then
	echo "64bit Detected" &&
	echo " " &&
	echo "Downloading File 2 of 3, 1 MB" &&
	echo " " &&
	wget http://kernel.ubuntu.com/~kernel-ppa/mainline/v3.10.6-saucy/linux-headers-3.10.6-031006-generic_3.10.6-031006.201308112316_amd64.deb &&
	echo " " &&
	echo "Downloading File 3 of 3, 44 MB" &&
	echo " " &&
	wget http://kernel.ubuntu.com/~kernel-ppa/mainline/v3.10.6-saucy/linux-image-3.10.6-031006-generic_3.10.6-031006.201308112316_amd64.deb
else
	echo "32bit Detected" &&
	echo " " &&
	echo "Downloading File 2 of 3, 1 MB" &&
	echo " " &&
	wget http://kernel.ubuntu.com/~kernel-ppa/mainline/v3.10.6-saucy/linux-headers-3.10.6-031006-generic_3.10.6-031006.201308112316_i386.deb &&
	echo " " &&
	echo "Downloading File 3 of 3, 43 MB" &&
	wget http://kernel.ubuntu.com/~kernel-ppa/mainline/v3.10.6-saucy/linux-image-3.10.6-031006-generic_3.10.6-031006.201308112316_i386.deb
fi &&
echo " " &&
echo "Installing Kernel" &&
echo "This step will require you password." &&
echo "This is the last step you can safely cancel at." &&
echo "Use Ctrl+C to cancel." &&
echo " " &&
sudo dpkg -i *.deb &&
echo " " &&
echo "Installation Complete" &&
echo " " &&
read -p "Press Enter to Delete the Downloads, or CTRL+C to keep them." nothing &&
echo " " &&
sudo rm -rf $HOME/kernel-htu
