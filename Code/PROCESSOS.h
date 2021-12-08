//criação da estrutura do tipo Processo
typedef struct {
    int Hora, Min, Seg;
}Tempo;
typedef struct {
    int Prioridade, PID;
    struct Tempo *Hora_Atual;

} Processo;

//funções de tempo
void inicializa_Tempo(Tempo *horario);
//funções com Processo
void inicializa_Processo(Processo *processo);

//PID
int get_PID(Processo *processo);

int set_PID(Processo *processo, Novo_PID);

//Prioridade
int set_Prioridade(Processo *processo, Nova_Prioridade);

int get_Prioridade(Processo *processo);

//Hora de Criação

int set_Hora(Processo *processo, Novo_seg, Novo_Min, Nova_Hora);

int get_Hora(Processo *processo);