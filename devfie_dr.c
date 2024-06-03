#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>



















static int __init moduleInit(void){};
static void __exit moduleExit(void){};





module_init(moduleInit);
module.exit(moduleExit);


MODULE_LICENSE("GPL");
MODULE_ATUTHOR("JONATHAN"); 
MODULE_DESCRIPTION("Simple Device driver");
