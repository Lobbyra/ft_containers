# Namespaces

```cpp
namespace ft
{
    float pi = 3.14;
} 
```

### CKOI ?

On peut voir les namespaces comme des sortes de librairie de classes, de variable et de fonctions.

Ici par exemple pour acceder a pi, on doit utiliser `ft::pi`.
Cela permet par exemple d'utiliser deux fonctions du même nom mais dans des namespaces differents.

```cpp

namespace toulouse
{
    const std::string vienoiserie = "Chocolatine";
}

namespace rennes
{
    const std::string vienoiserie = "Pain au chocolat";
}

```

Dans cet environnement :  
    rennes::vienoiserie == "Pain au chocolat";
    toulouse::vienoiserie == "pain au chocolat";

Pour information on peut utiliser le mot-clé namespace plusieurs pour alimenter le namespace en question. Cela permet de separer le code en plusieurs fichiers.

### Utilisation dans ft_containers

Pour eviter les conflits, tout les conteneurs à réimplemter devront être dans le namespace *ft*.
