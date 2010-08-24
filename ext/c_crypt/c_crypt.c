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

// Define CCrypt and the fact it has a class method called crypt3
void Init_c_crypt() {
  CCrypt = rb_define_module("CCrypt");
  int arg_count = 2;
  rb_define_module_function(CCrypt, "crypt3", method_crypt3, arg_count);
}

// Implement CCrypt.crypt3
VALUE method_crypt3(VALUE self, VALUE str_arg, VALUE salt_arg) {
  // Convert args from ruby strings into char arrays
  char* str = RSTRING(str_arg)->ptr;
  char* salt = RSTRING(salt_arg)->ptr;

  // Get back the hashed array string
  char *hashed = crypt(str, salt);

  // Cast it into a ruby string and return it
  return rb_str_new2(hashed);
}
