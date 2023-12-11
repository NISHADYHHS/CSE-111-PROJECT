from django.urls import path
from . import views
from .views import activate_moves
from .views import add_trainer_pokemon
from .views import update_trainer_pokemon
from .views import kill_trainer_pokemon

urlpatterns = [
    path('', views.home, name='home'),
    path('pokemon/', views.pokemon, name='pokemon'),
    path('teams/', views.teams, name='teams'),
    path('map/', views.location, name='locations'),
    path('trainer/', views.trainer, name='trainer'),
    path('pokemon/<str:pokemon_name>/', views.pokemon_card, name='pokemon_card'),
    path('trainer/<str:trainer_name>/', views.trainer_card, name='trainer_card'),
    path('pokemonT/<str:pokemon_name>/', views.pokemon_cardT, name='pokemon_cardT'),
    path('create_new_team/', views.create_new_team, name='create_new_team'),  # Add this line
    path('edit_team/', views.edit_team, name='edit_team'),  # Add this line
    path('edit_pokemon/<int:pokemon_id>/<int:trainer_id>/', views.edit_pokemon, name='edit_pokemon'),
        path('add_new_pokemon/', views.add_new_pokemon, name='add_new_pokemon'),  # Add this line

        path('activate_moves/<int:selected_pokemon_id>/', activate_moves, name='activate_moves'),
    path('addTrainerPokemon/<int:pokemon_id>/<str:selectMove1>/<str:selectMove2>/<str:selectMove3>/<str:selectMove4>/<int:selectedLevel>/<int:trainerId>/<str:selectedItem>/', add_trainer_pokemon, name='add_trainer_pokemon'),
     path('updateTrainerPokemon/<int:pokemon_id>/<str:selectMove1>/<str:selectMove2>/<str:selectMove3>/<str:selectMove4>/<int:selectedLevel>/<int:trainerId>/<str:selectedItem>/', update_trainer_pokemon, name='update_trainer_pokemon'),
    path('killTrainerPokemon/<int:pokemon_id>/<str:selectMove1>/<str:selectMove2>/<str:selectMove3>/<str:selectMove4>/<int:selectedLevel>/<int:trainerId>/<str:selectedItem>/', kill_trainer_pokemon, name='kill_trainer_pokemon'),


]