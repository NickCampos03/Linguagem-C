#include <ctype.h>
#include <string.h>
#include "constantes.h" //Constantes, macros e estruturas de dados
#include "stringaux.h"  //Fun��es auxiliares para tratar strings

/*----------------------------------------------------------------------------*/
/* strupper()                                                                 */
/* s --> a string � passada para caracteres mai�sculos                        */
/*----------------------------------------------------------------------------*/
void strupper(char *s)
{
  char *p = s;
  while (*p) {
    *p = toupper(*p);
    ++p;
  }
}

/*----------------------------------------------------------------------------*/
/* subString()                                                                */
/* input     --> string de origem                                             */
/* offset    --> posi��o inicial a partir de onde inicia a c�pia              */
/* len       --> quantidade de caracteres que copiar� a partir de offset      */
/*               (inclusive)                                                  */
/* dest      --> string de destino da c�pia                                   */
/* destSize  --> indica o tamanhp m�ximo que dest suporta, evitando assim     */
/*               buffer overflow                                              */
/*----------------------------------------------------------------------------*/
char* subString (const char* input, int offset, int len, char* dest, int destSize)
{
  int i = 0;
  int input_len = strlen(input);

  if (offset + len > input_len){  //Verifica se est� copiando fora dos limites da string
     return NULL;                 //de origem
  }

  int quantidade = min(len, destSize-1); //Protege contra transbordamento
  for (i = 0; i < quantidade; i++) {
    *(dest+i) = *(input + offset +i);
  }
  *(dest+i) = '\0';                      //Coloca o finalizador de string
  return dest;
}
