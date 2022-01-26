#include <stdio.h>
#include <glib.h>

typedef struct pokemon
{
    char *name;
    char *description;
    int rarity;
} * Pokemon;

typedef struct pokedex
{
    GHashTable *pokemonsByName;
} * Pokedex;

Pokemon pokemon_new(char *name, char *description, int rarity)
{
    Pokemon pokemon = g_malloc(sizeof(struct pokemon));

    pokemon->name = g_strdup(name);
    pokemon->description = g_strdup(description);
    pokemon->rarity = rarity;

    return pokemon;
}

void pokemon_destroy(Pokemon pokemon)
{
    g_free(pokemon->name);
    g_free(pokemon->description);
    g_free(pokemon);
}

void pokemon_destroy_glibsafe(gpointer e)
{
    Pokemon pokemon = (Pokemon)e;
    g_free(pokemon->name);
    g_free(pokemon->description);
    g_free(pokemon);
}

void pokemon_print(Pokemon pokemon)
{
    printf("Pokemon(name=\"%s\", description=\"%s\", rarity=%d)\n", pokemon->name, pokemon->description, pokemon->rarity);
}

void pokemon_print_glibsafe(gpointer key, gpointer value, gpointer user_data)
{
    if (user_data == NULL)
    {
        pokemon_print((Pokemon)value);
    }
    else
    {
        int *count = (int *)user_data;
        printf("This is pokemon #%d\n", *count);
        pokemon_print((Pokemon)value);
        (*count)++;
    }
}

void pokedex_destroy(Pokedex pokedex)
{
    g_hash_table_destroy(pokedex->pokemonsByName);
    g_free(pokedex);
}

void pokedex_insert(Pokedex pokedex, char *name, Pokemon pokemon)
{
    g_hash_table_insert(pokedex->pokemonsByName, g_strdup(name), pokemon);
}

Pokedex pokedex_new()
{
    Pokedex pokedex = g_malloc(sizeof(struct pokedex));

    pokedex->pokemonsByName = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, pokemon_destroy_glibsafe);

    return pokedex;
}

gboolean pokedex_exists(Pokedex pokedex, char *name)
{
    return g_hash_table_lookup(pokedex->pokemonsByName, name) != NULL;
}

void pokedex_print(Pokedex pokedex)
{
    g_hash_table_foreach(pokedex->pokemonsByName, pokemon_print_glibsafe, NULL);
}

void pokedex_print_with_counter(Pokedex pokedex)
{
    int count = 1;
    g_hash_table_foreach(pokedex->pokemonsByName, pokemon_print_glibsafe, &count);
}

void scenario_A()
{
    Pokemon charmander = pokemon_new("charmander", "cauda de fogo", 1);
    pokemon_print(charmander);

    Pokedex oak_pokedex = pokedex_new();
    pokedex_insert(oak_pokedex, charmander->name, charmander);

    printf("Does Charmander exist? %d\n", pokedex_exists(oak_pokedex, "charmander"));
    printf("Does Balbasaur exist? %d\n", pokedex_exists(oak_pokedex, "balbasaur"));

    Pokemon balbasaur = pokemon_new("balbasaur", "costas de orquidea", 1);
    pokedex_insert(oak_pokedex, balbasaur->name, balbasaur);
    printf("What about now, does Balbasaur exist? %d\n", pokedex_exists(oak_pokedex, "balbasaur"));

    pokedex_destroy(oak_pokedex);
}

void scenario_B()
{
    Pokedex oak_pokedex = pokedex_new();

    Pokemon charmander = pokemon_new("charmander", "cauda de fogo", 1);
    Pokemon balbasaur = pokemon_new("balbasaur", "costas de orquidea", 1);
    Pokemon squirtle = pokemon_new("squirtle", "costas duras", 1);
    Pokemon articuno = pokemon_new("articuno", "gajo azul", 10);

    pokedex_insert(oak_pokedex, charmander->name, charmander);
    pokedex_insert(oak_pokedex, balbasaur->name, balbasaur);
    pokedex_insert(oak_pokedex, squirtle->name, squirtle);
    pokedex_insert(oak_pokedex, articuno->name, articuno);

    pokedex_print(oak_pokedex);
}

void scenario_C()
{
    Pokedex oak_pokedex = pokedex_new();

    Pokemon charmander = pokemon_new("charmander", "cauda de fogo", 1);
    Pokemon balbasaur = pokemon_new("balbasaur", "costas de orquidea", 1);
    Pokemon squirtle = pokemon_new("squirtle", "costas duras", 1);
    Pokemon articuno = pokemon_new("articuno", "gajo azul", 10);

    pokedex_insert(oak_pokedex, charmander->name, charmander);
    pokedex_insert(oak_pokedex, balbasaur->name, balbasaur);
    pokedex_insert(oak_pokedex, squirtle->name, squirtle);
    pokedex_insert(oak_pokedex, articuno->name, articuno);

    pokedex_print_with_counter(oak_pokedex);
}

int main()
{
    scenario_C();
}