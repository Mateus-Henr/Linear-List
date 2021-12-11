/* Estrutura abstrata para processo
 Essa estrutura é usada para representar um processo no qual possui:
    - Código de identificação do processo (aleatório).
    - Prioridade do processo (1 a 5).
    - Hora de criação do processo (foi definida uma estrutura para tal objetivo a fim de facilitar a manipulação).
 Além de possuir funções para manipulação da estrutura.
 */

typedef struct
{
    int horas;;
    int minutos;
    int segundos;
} Hora;

typedef struct
{
    int PID;
    int prioridade;
    Hora hora;

} Processo;

Processo inicializa_processo();

void inicializa_tempo(Processo *processo);

// Retorna hora no formato "00:00:00"
char *formata_hora(Hora *hora);


// Getters e Setters

int get_PID(Processo *processo);

void set_PID(Processo *processo, int novo_PID);

int get_prioridade(Processo *processo);

void set_prioridade(Processo *processo, int nova_prioridade);

Hora get_hora(Processo *processo);

void set_hora(Processo *processo, int nova_hora, int novo_minuto, int novo_segundo);
