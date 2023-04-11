typedef struct restaurante Restaurante;
typedef struct reserva Reserva;
typedef struct fila Fila;

Fila* fila_cria(void);

Restaurante* CriaR(void);
Reserva* CriaRV(void);

void addAtributos(Restaurante *r);
void addreserva(Fila *rv);
void delreserva(Fila *rv);
void editreserva(Fila *rv);
void buscareserva(Fila *rv);
void listar(Fila *rv);
void consultareservas(Restaurante *r, Fila *rv);

