#include <string>

enum Digit {
  ZERO = 0,
  ONE = 1,
  TWO = 2,
  THREE = 3,
  FOUR = 4,
  FIVE = 5,
  SIX = 6,
  SEVEN = 7,
  EIGHT = 8,
  NINE = 9
};

// Helpers para enum Digit
char digit_to_char(Digit dg);
Digit char_to_digit(char c);

enum Operator {
  SUM = 10,
  SUBTRACTION = 11,
  DIVISION = 12,
  MULTIPLICATION = 13,
  PERCENTAGE = 14,
  SQUARE_ROOT = 15
};

enum Control {
  // ON = 16, // O que isso deveria fazer?
  OFF = 17,
  CLEAR_ERROR = 18,
  // TODO: Isso não deveria ser dividido?
  // MEMORY_READ_CLEAR = 19,
  MEMORY_READ = 19,
  MEMORY_CLEAR = 20,
  MEMORY_SUM = 21,
  MEMORY_SUBTRACTION = 22,
  EQUAL = 23,
  DECIMAL_SEPARATOR = 24
};

class Display {
private:
  char buffer[8];
  int sizeBuffer;
  int decimalFlag;
  int negativeFlag;
  int memFlag;
  int clearedFlag;
  void flush();
public:
  Display();
  void set_negative();
  void set_mem();
  void print();
  void error();
  void add(char c);
  void decimal_separator();
  void clear();
  void clear_buffer();
};

class Cpu {
  private:
    Display* displ;

    enum Sign{
      POSITIVE,
      NEGATIVE
    };
  
    std::string reg1;
    Sign reg1Sign;
    std::string reg2;
    Sign reg2Sign;
    std::string mem;
    Operator currentOp;
    bool errorFlag;

    // Helpers
    Digit to_char(char c);
    void result();
    void error();
    double reg1_to_double();
    double reg2_to_double();

    // OPERATOR
    void add();
    void sub();
    void div();
    void mult();
    void sqrt();
    void percen();

    // CONTROL
    // Memory
    void mem_sum();
    void mem_sub();
    void mem_read();
    void mem_clear();
    // Others
    void decimal_separator();
    void clear();
    void off() { exit(0); }
    void equal();

  public:
    Cpu();
    ~Cpu();
    void send_digit(Digit dg);
    void send_control(Control ctrl);
    void send_operator(Operator op);
    void set_display(Display *ds);
};