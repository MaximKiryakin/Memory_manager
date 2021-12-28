extern int descriptor_of_last();
extern int del (int);
extern int key_right[];
extern int size_blok[];
extern int key_number;
extern int number_of_desc;
enum{MASS_SIZE = 100000};

extern char data[];

int alloc (int n);
int del (int descriptor);
int read_byte(int descriptor, int delta);
int write_byte(int descriptor, int delta, char data_char);
int reallocc (int descriptor, int new_size);
int get_max_str();
int get_max_str_size();
