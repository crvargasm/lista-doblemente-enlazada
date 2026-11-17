# Lista Doblemente Enlazada en C

Implementación desde cero de una lista doblemente enlazada, con manejo manual de memoria (`malloc`/`free`) y cubriendo todos los casos borde.

## Operaciones

| Función | Complejidad | Descripción |
|---|---|---|
| `insert_head(D_List *list, int value)` | O(1) | Inserta al inicio |
| `insert_tail(D_List *list, int value)` | O(1) | Inserta al final |
| `print(D_List list)` | O(n) | Recorre e imprime la lista con su Head, Tail y Size |
| `pop(D_List *list)` | O(1) | Elimina el primer elemento |
| `delete_last(D_List *list)` | O(1) | Elimina el último elemento |
| `delete(D_List *list, int value)` | O(n) | Elimina por valor |
| `search(D_List list, int value)` | O(n) | Devuelve el nodo o `NULL` |
| `update(D_List list, int old, int new)` | O(n) | Cambia un valor |
| `free_list(D_List *list)` | O(n) | Libera todos los nodos y vacía la Lista |

## Compilar y ejecutar

```bash
gcc -fsanitize=address main.c -o main && ./main
```
