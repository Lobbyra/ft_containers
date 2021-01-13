# std::stack
![img_stack][img_stack]

Une *stack* (pile en anglais) est stockée via le stockage de type LIFO.

### LIFO et pas lo-fi 🦊🎼 

##### Keskessé ?

> Le stockage LIFO (Last In, First Out | Dernier arrivé, premier sorti) est un stockage en pile. Le **dernier** élément inséré dans la pile est le **premier** que vous liriez en accedant à la pile.

> Pour votre culture personnel, il existe aussi le stockage FIFO (First In, First Out) ! C'est tout à fait l'inverse, le **premier** element que vous avez mis dans la pile, sera selui que vous **lirez** en regardant dans la pile !

##### Pourquoi utiliser celui la ?

> Je penses qu'il n'y a pas vraiment d'avantage technique a utiliser une stack plutot qu'autre choses. C'est surtout un choix a faire quand on peut utiliser une stack pour limiter les possibilités de notre partie du programme. En utilisant une stack, on sais directement a quoi on a affaire.

### Quels sont les fonctionnalités de ce conteneurs ?

Ce conteneurs contient les *opérateur rationnels*.
Ce sont les fonctions de surcharge d'operateur sur ces operateurs : ==, !=, <, <=, >, >=

##### Attributs

`` : 
``
``

##### Fonctions membres

Constructeur par défault accéssible.
```cpp
stack::stack(void)
```
Constructeur par défault copie.
```cpp
stack::stack(stack const &x);
```

empty() : Retourne True si la stack est vide, False sinon.
```cpp
bool empty() const;
```

size() : Retourne le nombre d'éléments dans la *stack*.
```cpp
size_type size() const;
```

top() : Retourne l'élément au dessus de la *stack*.
```cpp
value_type& top() const;
const value_type& top() const;
```

push() : Met l'élément au dessus de la pile.
```cpp
void push (const value_type& val);
```

pop() : Supprime l'élément au dessus de la pile.
```cpp
void pop();
```


[img_stack]: https://i.imgur.com/APx3GyX.jpeg
