// Criação da estrutura abstrata do tipo Processo
typedef struct
{
    int horas;
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
void inicializa_Tempo(Hora *hora);

// Funções com Processo
void inicializa_Processo(Processo *processo);


// Getters e Setters

// PID
int get_PID(Processo *processo);

void set_PID(Processo *processo, int novo_PID);

// Prioridade
void set_Prioridade(Processo *processo, int nova_prioridade);

int get_Prioridade(Processo *processo);

// Hora
void set_Hora(Processo *processo, int nova_hora, int novo_minuto, int novo_segundo);

int get_Hora(Processo *processo);