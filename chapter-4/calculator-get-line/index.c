/* Exercise 4-10. An alternate organization uses getline to read an entire
  input line; this makes getch and ungetch unneccessary. Revise the
  calculator to use this approach. */

#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h> /* for sin(), exp(), pow() */

#define MAXOF 100   /* max size of operand or operator */
#define NUMBER '0'  /* signal that a number was found */

int get_line(char s[], int max_len);
int getop(char line[], char s[]);
void push(double);
void peek(void);
double pop(void);
void swap(void);
void duplicate(double copy[]);
void clear(void);

/* reverse Polish calculator */
int main()
{
  int type, var;
  double op2, v;
  char line[MAXOF];
  char s[MAXOF];
  double variable[26];

  while(get_line(line, MAXOF) > 0) {
    while ((type = getop(line, s)) != '\0') {
      switch (type) {
      case NUMBER:
        push(atof(s));
        break;
      case '=':
        pop();
        if (var >= 'A' && var <= 'Z')
          variable[var-'A'] = pop();
        else
          printf("error: no variable name\n");
        break;
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        op2 = pop();
        if (op2 != 0.0)
          push(pop() / op2);
        else
          printf("error: zero divisor\n");
        break;
      case '%':
        op2 = pop();
        push((int)pop() % (int)op2);
        break;
      case '^':
        op2 = pop();
        push(pow(pop(), op2));
        break;
      case 's':
        push(sin(pop()));
        break;
      case 'e':
        push(exp(pop()));
        break;
      case '\n':
        v = pop();
        printf("\t%.8g\n", v);
        break;
      default:
        if (type >= 'A' && type <= 'Z')
          push(variable[type-'A']);
        else if (type == 'v')
          push(v);
        else
          printf("error: unknown command %s\n", s);
        break;
      }
      var = type;
    }
  }
  return 0;
}

#define MAXVAL 100  /* maximum depth of val stack */

int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f)
{
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n", f);
}

/* peek: print top value from the stack without popping */
void peek(void)
{
  if (sp > 0)
    printf("%f\n", val[sp-1]);
  else {
    printf("error: stack empty\n");
  }
}

/* pop: pop and return top value from stack */
double pop(void)
{
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

/* swap: swap top two elements of stack */
void swap(void)
{
  double temp;
  if (sp > 1) {
    temp = val[sp-2];
    val[sp-2] = val[sp-1];
    val[sp-1] = temp;
  } else {
    printf("error: stack does not have two elements to swap\n");
  }
}

/* duplicate: duplicate the stack */
void duplicate(double copy[])
{ 
  int i;
  for (i = 0; i < sp; i++)
    copy[i] = val[i];
}

/* clear: clear the stack */
void clear(void)
{
  sp = 0;
}

#include <ctype.h>

int p = 0;

/* get a line of input */ 
int get_line(char s[], int max_len)
{
  int i, c;
  for (i = 0; i < max_len && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c != EOF)
    s[i++] = '\n';
  s[i] = '\0';
  p = 0;
  return i;
}

/* getop: get next operator or numeric operand */
int getop(char line[], char s[])
{
  int i, c;

  while((s[0] = c = line[p++]) == ' ' ||  c == '\t')
    ;
  s[1] = '\0';
  if (!isdigit(c) && c != '.' && c != '-')
    return c; /* not a number */
  i = 0;
  if (isdigit(c) || c == '-') /* collect integer part */
    while (isdigit(s[++i] = c = line[p++]))
      ;
  if (c == '.') /* collect fraction part */
    while (isdigit(s[++i] = c = line[p++]))
      ;
  s[i] = '\0';
  if (c != '\0')
    p--;
  return (i == 1 && s[0] == '-') ? '-' : NUMBER;
}