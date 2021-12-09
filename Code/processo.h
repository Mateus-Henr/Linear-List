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
    struct Hora *hora;

} Processo;

// Funções de tempo
void inicializa_Tempo(Processo *processo);

// Funções com Processo
Processo inicializa_Processo();


// Getters e Setters

// PID
int get_PID(Processo *processo);

void set_PID(Processo *processo, int novo_PID);

// Prioridade
int get_Prioridade(Processo *processo);

void set_Prioridade(Processo *processo, int nova_prioridade);

// Hora

void set_Hora(Processo *processo, int nova_hora, int novo_minuto, int novo_segundo);