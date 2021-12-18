/* Estrutura abstrata para processo
 Essa estrutura é usada para representar um processo no qual possui:
    - Código de identificação do processo (aleatório).
    - Prioridade do processo (1 a 5).
    - Hora de criação do processo (foi usada a estrutura tm para manipulação).
 Além de possuir funções para manipulação da estrutura.
 */

typedef struct
{
    unsigned int PID;
    unsigned int prioridade;
    struct tm *hora;

} TProcesso;

TProcesso *inicializa_processo();

void inicializa_tempo(TProcesso *processo);

// Retorna hora no formato "00:00:00"
char *get_hora(TProcesso *processo);


// Getters e Setters

unsigned int get_PID(TProcesso *processo);

void set_PID(TProcesso *processo, unsigned int novo_PID);

unsigned int get_prioridade(TProcesso *processo);

void set_prioridade(TProcesso *processo, unsigned int nova_prioridade);
