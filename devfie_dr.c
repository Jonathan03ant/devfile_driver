#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>


# define MYMAJOR 19; //This number is defined for the device file's major number when we register it



/*
 	*@NOTE 
 * When a user application calls open on a device file, the kernel will forward the call to this function.
 * inode dev_file is needed for the actual driver to determine permission, check major and minor number etc
 * the file instance is created after the device file is opned.
 */

static struct file_operation fops = {
	.owner = THIS_MODULE, 
	.open = devFileOpen,
	.release = devFileRelease
};

static int defFileOpen(struct inode *deviceFile, struct file *instance){
	printk("device driver -- open was called");
	return 0;

};


static int defFileRelease (struct inode *deviceFile, struct file *instance){
	printk("device driver -- close was called\n");
	return 0;
};



static int __init moduleInit(void){
	/*
	 * Here is when we will initialize the device file with minor and major no
	 * registering the dev file with major and minor numbers
	 */



};


static void __exit moduleExit(void){
	/*
	 * Unregister the register device
	 * print something
	 */

	printk("Hello from Kernel");
	int success;

	/*
	 * Register device nummber
	 */
	success = register_chrdev(MYMAJOR, "joesDeviceFile", &fops);

	if (success == 0){
	
	} else if (success > 0) {

	} else {

	};
};





module_init(moduleInit);
module.exit(moduleExit);


MODULE_LICENSE("GPL");
MODULE_ATUTHOR("JONATHAN"); 
MODULE_DESCRIPTION("Simple Device driver");
