#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>

#define MYMAJOR 19

static int devFileOpen(struct inode *deviceFile, struct file *instance){
    printk(KERN_INFO "device driver -- open was called\n");
    return 0;
};

static int devFileRelease(struct inode *deviceFile, struct file *instance){
    printk(KERN_INFO "device driver -- close was called\n");
    return 0;
};

static struct file_operations fops = {
   .owner = THIS_MODULE,
   .open = devFileOpen,
   .release = devFileRelease
};

static void __exit moduleStop(void){
    unregister_chrdev(MYMAJOR, "joesDeviceFile");
    printk(KERN_INFO "Good bye from Kernel\n");
}

static int __init moduleStart(void){
    printk(KERN_INFO "Hello from Kernel\n");

    int success;

    success = register_chrdev(MYMAJOR, "joesDeviceFile", &fops);

    if (success == 0){
        printk(KERN_INFO "Device driver is registered with device number Major: %d, Minor: %d\n", MYMAJOR, 0);    
    } else if (success > 0) {
        printk(KERN_INFO "Device driver is registered with device number Major: %d, Minor: %d\n", MYMAJOR, success >> 20 & 0xfffff);
    } else {
        printk(KERN_INFO "Could not register device\n");
        return -1;
    }

    return 0;
}

module_init(moduleStart);
module_exit(moduleStop);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Jonathan");
MODULE_DESCRIPTION("Simple Device driver");
