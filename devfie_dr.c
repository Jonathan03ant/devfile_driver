#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>








/*
 * When a user application calls open on a device file, the kernel will forward the call to this function.
 * inode dev_file is needed for the actual driver to determine permission, check major and minor number etc
 * the file instance is created after the device file is opned.
 */

static int devfile_open ( struct inode *dev_file, struct file *opened_instance ) {

};


static int devfile_close (struct inode *devfile, struct file *instance){
};











static int __init moduleInit(void){};
static void __exit moduleExit(void){};





module_init(moduleInit);
module.exit(moduleExit);


MODULE_LICENSE("GPL");
MODULE_ATUTHOR("JONATHAN"); 
MODULE_DESCRIPTION("Simple Device driver");
