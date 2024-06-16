#include <stdio.h>
#include <string.h>
#include "os_file.h"
#pragma warning(disable:4996)

int main(void)
{
    file_manager_t fm, mm;
    setup_file_manager(&fm);
    setup_file_manager(&mm);
    char* cur_dir = (char*)calloc(128, sizeof(char));
    //int result = fm.create(15);
    //printf("%d\n", result);
    ////int result = fm.create(15);
    ////printf("%d\n", result);
    ////result = fm.destroy();
    ////printf("%d\n", result);
    //result = fm.free_space();
    //printf("%d\n", result);
    //result = fm.create_dir("sardor");
    //printf("%d\n", result);
    //result = fm.create_dir("sardor/u");
    //printf("%d\n", result);
    //result = fm.create_dir("sardor/uty/jhbhvhh");
    //file_manager_t fm;
    //setup_file_manager(&fm);
    //char* dst = (char*)calloc(128, sizeof(char));
    //int result = fm.create(1000);
    //printf("%d\n", result);
    ////result = fm.create_file("test_file", 1000 + 1);
    ////printf("%d\n", result);
    //result = fm.create_dir("/dir1");
    //printf("%d\n", result);
    //result = fm.create_dir("/dir1/dir11");
    //printf("%d\n", result);
    //result = fm.change_dir("dir1");
    //printf("%d\n", result);
    //fm.get_cur_dir(dst);
    //printf("%s\n", dst);
    //result = fm.create_file("test_file", 100);
    //printf("%d\n", result);
    //result = fm.remove("test_file", 1);
    //printf("%d\n", result);
    //result = fm.destroy();
    //printf("%d\n", result);


 //int res = fm.create(1000);// expected= 1, passed
 //printf("%d\n", res);
 //res = fm.create_dir("dir1");// expected= 1, passed
 //printf("%d\n", res); 
 //res = fm.create_dir("dir1/dir11"); //expected= 1, passed
 //printf("%d\n", res); 
 //res = fm.change_dir("dir1");// expected= 1, passed
 //printf("%d\n", res); 
 //res = fm.create_dir("../dir2");// expected= 1, passed
 //printf("%d\n", res); 
 //res = fm.create_dir("../dir2/dir3");// expected= 1, passed
 //printf("%d\n", res); 
 //res = fm.remove("/dir2/dir3", 0);// expected= 1, passed
 //printf("%d\n", res); 
 //res = fm.create_dir("/dir3/dir31");// expected= 0, passed
 //printf("%d\n", res); 
 //res = fm.create_dir("../dir3/dir31");// expected= 0, passed
 //printf("%d\n", res); 
 //res = fm.create_dir("../dir2"); //expected= 0, passed
 //printf("%d\n", res); 
 //res = fm.create_file("/dir2/file1", 1);// expected= 1, passed
 //printf("%d\n", res);
 //res = fm.create_dir("/dir2/dir21");// expected= 1, passed
 //printf("%d\n", res);
 //res = fm.create_dir("/dir2/file1"); //expected= 0, passed
 //printf("%d\n", res);
 //res = fm.create_dir("../dir2/file1");// expected= 0, passed
 //printf("%d\n", res);
 //res = fm.create_dir("../dir2/file1/dir");// expected= 0, passed
 //printf("%d\n", res); 
 //res = fm.create_dir("../dir2/dir22"); //expected= 1, passed
 //printf("%d\n", res); 
 //res = fm.create_dir(".."); //expected= 0, passed
 //printf("%d\n", res); 
 //res = fm.create_dir("../dir2/.");// expected= 0, passed
 //printf("%d\n", res); 
 //res = fm.change_dir("dir2"); //expected= 0, passed
 //printf("%d\n", res); 
 //res = fm.change_dir("dir11");// expected= 1, passed
 //printf("%d\n", res); 
 //res = fm.remove("../../dir2/file1", 0);// expected= 1, passed
 //printf("I'm remove - %d\n", res); 
 //res = fm.create_dir("../../dir2/file1");// expected= 1, passed
 //printf("%d\n", res); 
 //res = fm.remove("../../dir2/file1", 0);// expected= 1, passed
 //printf("%d\n", res); 
 //res = fm.create_dir("../../dir2/file1");// expected= 1, passed
 //printf("%d\n", res); 
 //res = fm.remove("../../dir2/file1", 0);// expected= 1, passed
 //printf("%d\n", res); 
 //res = fm.create_file("../../dir2/file1", 1);// expected= 1, passed
 //printf("%d\n", res); 
 //res = fm.change_dir("."); //expected= 1, passed
 //printf("%d\n", res); 
 //res = fm.change_dir("/dir1/dir11");// expected= 1, passed
 //printf("%d\n", res); 
 //res = fm.change_dir("/dir1/dir11/dir3");// expected= 0, passed
 //printf("%d\n", res); 
 //res = fm.change_dir("/dir1");// expected= 1, passed
 //printf("%d\n", res); 
 //res = fm.change_dir("./dir11");// expected= 1, passed
 //printf("%d\n", res); 
 //res = fm.change_dir(".."); //expected= 1, passed
 //printf("%d\n", res); 
 //res = fm.create_file("ddir2/file1", 1000 - 1); //expected= 0, passed
 //printf("%d\n", res); 
 //res = fm.create_file("./dir11/file.txt", 1); //expected= 1, passed
 //printf("%d\n", res); 
 //res = fm.remove("dir11", 0); //expected= 0, passed
 //printf("%d\n", res); 
 //res = fm.remove("./dir11", 0); //expected= 0, passed
 //printf("%d\n", res); 
 //res = fm.remove("./dir11", 1); //expected= 1, passed
 //printf("%d\n", res); 
 //fm.get_cur_dir(cur_dir);
 //printf("%s\n", cur_dir);
 //printf("%d\n", strcmp(cur_dir, "/dir1") == 0 || strcmp(cur_dir, "/dir1/") == 0); //expected= 1, passed

 //res = fm.destroy(); //expected= 1, passed
 //printf("%d\n", res);

 //Test 3

int TOTAL_SIZE = 10000;

int res = mm.create(TOTAL_SIZE);// expected= 1, passed
printf("%d\n", res);
res = mm.create_dir("dir1");// expected= 1, passed
printf("%d\n", res);
res = mm.create_dir("dir1/dir11");// expected= 1, passed
printf("%d\n", res); 
res = mm.change_dir("dir1");// expected= 1, passed
printf("%d\n", res); 
res = mm.create_dir("../dir2");// expected= 1, passed
printf("%d\n", res); 
res = mm.create_dir("../dir2/dir3");// expected= 1, passed
printf("%d\n", res);
res = mm.remove("/dir2/dir3", 0);// expected= 1, passed
printf("%d\n", res);
res = mm.create_dir("/dir3/dir31");// expected= 0, passed
printf("%d\n", res);
res = mm.create_dir("../dir3/dir31");// expected= 0, passed
printf("%d\n", res);
res = mm.create_dir("../dir2");// expected= 0, passed
printf("%d\n", res);
res = mm.create_file("/dir2/file1", 1);// expected= 1, passed
printf("%d\n", res);
res = mm.create_dir("/dir2/dir21");// expected= 1, passed
printf("%d\n", res);
res = mm.create_dir("/dir2/file1");// expected= 0, passed
printf("%d\n", res);
res = mm.create_dir("../dir2/file1");// expected= 0, passed
printf("%d\n", res);
res = mm.create_dir("../dir2/file1/dir");// expected= 0, passed
printf("%d\n", res);
res = mm.create_dir("../dir2/dir22");// expected= 1, passed
printf("%d\n", res);
res = mm.change_dir("dir2");// expected= 0, passed
printf("%d\n", res);
res = mm.change_dir("dir11");// expected= 1, passed
printf("%d\n", res);
res = mm.remove("../../dir2/file1", 0);// expected= 1, passed
printf("%d\n", res);
res = mm.create_dir("../../dir2/file1");// expected= 1, passed
printf("%d\n", res);
res = mm.remove("../../dir2/file1", 0);// expected= 1, passed
printf("%d\n", res);
res = mm.create_file("../../dir2/file1", 2);// expected= 1, passed
printf("%d\n", res);
res = mm.change_dir(".");// expected= 1, passed
printf("%d\n", res);
res = mm.change_dir("/dir1/dir11");// expected= 1, passed
printf("%d\n", res);
res = mm.change_dir("/dir1/dir11/dir3");// expected= 0, passed
printf("%d\n", res);
res = mm.change_dir("/dir1");// expected= 1, passed
printf("%d\n", res);
res= mm.change_dir("./dir11");// expected= 1, passed
printf("%d\n", res);
res = mm.change_dir("..");// expected= 1, passed
printf("%d\n", res);
res = mm.create_file("./dir11/file.txt", 6);// expected= 1, passed
printf("%d\n", res);
res = mm.remove("dir11", 0);// expected= 0, passed
printf("%d\n", res);
res = mm.remove("./dir11", 0);// expected= 0, passed
printf("%d\n", res);
res = mm.remove("./dir11", 1);// expected= 1, passed
printf("%d\n", res);
res = mm.create_file("file11.txt", 9);// expected= 1, passed
printf("%d\n", res);
res = mm.create_file("../dir2/a_file22.txt", 2);// expected= 1, passed
printf("%d\n", res);
res = mm.free_space();
printf("%d\n", res);
res = mm.destroy();// expected= 1, passed
printf("%d\n", res);


    /*//file_manager_t fm;

    //setup_file_manager(&fm);

    //int res = fm.create(100);// expected 1, not passed
    //printf("%d\n", res);
    //res = fm.create_file("f1", 1);// expected 1, not passed
    //printf("%d\n", res);
    //res = fm.create_file("f1", 5);// expected 0, not passed
    //printf("%d\n", res);
    //res = fm.create_dir("d3");// expected 1, not passed
    //printf("%d\n", res);
    //res = fm.create_dir("/d2");// expected 1, not passed
    //printf("%d\n", res);
    //res = fm.create_dir("d1");// expected 1, not passed
    //printf("%d\n", res);
    //res = fm.create_file("d1/f11", 102);// expected 0, not passed
    //printf("%d\n", res);
    //res = fm.create_file("d1/f11", 2);// expected 1, not passed
    //printf("%d\n", res);
    //res = fm.create_dir("/d1/d14");// expected 1, not passed
    //printf("%d\n", res);
    //res = fm.create_dir("/d1/d13");// expected 1, not passed
    //printf("%d\n", res);
    //res = fm.create_dir("/d1/d12");// expected 1, not passed
    //printf("%d\n", res);
    //res = fm.create_dir("/d1/d11");// expected 1, not passed
    //printf("%d\n", res);
    //res = fm.create_dir("/d1/d11/d113");// expected 1, not passed
    //printf("%d\n", res);
    //res = fm.create_dir("/d1/d14/d141");// expected 1, not passed
    //printf("%d\n", res);
    //res = fm.create_dir("/d1/d11/d112");// expected 1, not passed
    //printf("%d\n", res);
    //res = fm.change_dir("d1");// expected 1, not passed
    //printf("%d\n", res);
    //res = fm.create_dir("d11/d111");// expected 1, not passed
    //printf("%d\n", res);
    //res = fm.create_file("d14/f142", 5);// expected 1, not passed
    //printf("%d\n", res);
    //res = fm.create_file("d19/f142", 5);// expected 0, not passed
    //printf("%d\n", res);
    //res = fm.create_file("d14/f141", 6);// expected 1, not passed
    //printf("%d\n", res);
    */


    return 0;
}