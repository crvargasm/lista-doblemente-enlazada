/*
 * lista-doblemente-enlazada-c - Implementación de una lista doblemente enlazada
 * Copyright (C) 2026 Cristian Camilo Vargas Morales
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct D_Node {
  int value;
  struct D_Node *prev;
  struct D_Node *next;
} D_Node;

typedef struct D_List {
  D_Node *head;
  D_Node *tail;
  int size;
} D_List;

bool insert_head(D_List *list, int value) { // O(1)
  D_Node *new_node = malloc(sizeof(D_Node));
  new_node->value = value;
  if (list->head && list->tail) {
    new_node->next = list->head;
    list->head->prev = new_node;
  } else {
    list->tail = new_node;
  }
  list->head = new_node;
  list->size += 1;
  return true;
}

bool insert_tail(D_List *list, int value) { // O(1)
  D_Node *new_node = malloc(sizeof(D_Node));
  new_node->value = value;
  if (list->head && list->tail) {
    new_node->prev = list->tail;
    list->tail->next = new_node;
  } else {
    list->head = new_node;
  }
  list->tail = new_node;
  list->size += 1;
  return true;
}

void print(D_List list) { // O(n)
  D_Node *aux = list.head;
  if (!aux) {
    printf("Empty list\n");
    return;
  }
  while (aux) {
    printf("%d ", aux->value);
    aux = aux->next;
  }
  printf(" Head: %d, Tail: %d, Size: %d", list.head->value, list.tail->value,
         list.size);
  printf("\n");
  return;
}

bool pop(D_List *list) { // O(1)
  if (list->head) {
    D_Node *aux = list->head;
    aux->next->prev = aux->prev;
    list->head = aux->next;
    free(aux);
    list->size -= 1;
    return true;
  }
  return false;
}

bool delete_last(D_List *list) { // O(1)
  if (list->tail) {
    D_Node *aux = list->tail;
    aux->prev->next = aux->next;
    list->tail = aux->prev;
    free(aux);
    list->size -= 1;
    return true;
  }
  return false;
}

bool delete(D_List *list, int value) { // O(n)
  D_Node *aux = list->head;
  while (aux) {
    if (aux->value == value) {
      if (aux->prev) {
        aux->prev->next = aux->next;
      } else {
        list->head = aux->next;
      }
      if (aux->next) {
        aux->next->prev = aux->prev;
      } else {
        list->tail = aux->prev;
      }
      free(aux);
      list->size -= 1;
      return true;
    }
    aux = aux->next;
  }
  return false;
}

D_Node *search(D_List list, int value) {
  D_Node *cur = list.head;
  while (cur) {
    if (cur->value == value) {
      return cur;
    }
    cur = cur->next;
  }
  return NULL;
}

bool update(D_List list, int old_value, int new_value) {
  D_Node *cur = list.head;
  while (cur) {
    if (cur->value == old_value) {
      cur->value = new_value;
      return true;
    }
    cur = cur->next;
  }
  return false;
}

bool free_list(D_List *list) {
  while (list->head) {
    D_Node *old = list->head;
    list->head = list->head->next;
    free(old);
  }
  list->size = 0;
  list->head = NULL;
  list->tail = NULL;
  return true;
}

int main() {
  D_List *mi_lista = malloc(sizeof(D_List));

  insert_head(mi_lista, 3);
  insert_head(mi_lista, 8);
  insert_tail(mi_lista, 2);
  insert_head(mi_lista, 1);
  insert_tail(mi_lista, 9);
  print(*mi_lista);

  pop(mi_lista);
  delete_last(mi_lista);
  print(*mi_lista);

  delete(mi_lista, 1);
  print(*mi_lista);

  printf("Longitud value: %d\n", mi_lista->size);

  D_Node *resultado = search(*mi_lista, 8);
  if (resultado) {
    printf("Hay resultado: %d\n", resultado->value);
  } else {
    printf("No hay resultado\n");
  }

  update(*mi_lista, 2, 4);
  print(*mi_lista);

  free_list(mi_lista);
  print(*mi_lista);
  return 0;
}
