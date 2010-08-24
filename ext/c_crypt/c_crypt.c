#include <ruby.h>
#ifdef __APPLE__
#include <unistd.h>
#else
#include <crypt.h>
#endif

// Define our module constant
VALUE CCrypt = Qnil;

// Prototype this
void Init_c_crypt();

// Prototype CCrypt.crypt3
VALUE method_crypt3();

// Define our module & method
void Init_c_crypt() {
  CCrypt = rb_define_module("CCrypt");
  int arg_count = 2;
  rb_define_module_function(CCrypt, "crypt3", method_crypt3, arg_count);
}

// Implement CCrypt.crypt3
VALUE method_crypt3(VALUE self, VALUE str_arg, VALUE salt_arg) {
  char* str = RSTRING(str_arg)->ptr;
  char* salt = RSTRING(salt_arg)->ptr;

//  printf("str: %s\n", str);
//  printf("salt: %s\n", salt);

  char *hashed = crypt(str, salt);

//  printf("hashed: %s\n", hashed);
  
  return rb_str_new2(hashed);
}

