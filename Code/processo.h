// Criação da estrutura abstrata do tipo Processo
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

// Funções de tempo
void inicializa_tempo(Processo *processo);

// Funções com Processo
Processo inicializa_processo();


// Getters e Setters

// PID
int get_PID(Processo *processo);

void set_PID(Processo *processo, int novo_PID);

// Prioridade
int get_prioridade(Processo *processo);

void set_prioridade(Processo *processo, int nova_prioridade);

// Hora
void set_hora(Processo *processo, int nova_hora, int novo_minuto, int novo_segundo);

char *formata_hora(Hora *hora);

Hora get_hora(Processo *processo);