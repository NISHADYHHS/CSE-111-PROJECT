from collections import defaultdict
from django.shortcuts import render
from django.http import HttpResponse
from django.template import loader
from .models import Pokemon
from .models import Wildencounter, Location, Weakness, Trainer, Trainerlocation, Item, Moves, Movetable
from .inputTeam import getTrainer
from .inputTeam import getTrainerKVers
from .inputTeam import getPokemonIDS
from .inputTeam import getPokemon
from .inputTeam import getAreas, getMoveIDFromName
from .inputTeam import addPlayer, getMoves, addTrainerPokemon, updatePokemon, killPokemon, softDel, getLocations
from django.http import JsonResponse

def home(request):
    return render(request, 'home.html')



def pokemon(request):
    mypokemon = Pokemon.objects.all().values()
    myweakness = Weakness.objects.all().values()
    mywildencounters = Wildencounter.objects.all().values()
    mywildpokemon = Wildencounter.objects.select_related('we_pokemonName').all()
    mywildLocations = Wildencounter.objects.select_related('we_locationID').all()
    mylocations = Location.objects.all().values()

    for pokemon in mypokemon:
        pokemon["p_locations"] = getLocations(pokemon["p_name"])
    

    template = loader.get_template('myhtml.html')
    context = {
        'mypokemon': mypokemon,
        'mylocations': mylocations,
        'mywildencounters': mywildencounters,
        'myweakness': myweakness,
         'mywildpokemon': mywildpokemon,
          'mywildLocations': mywildLocations,
          
    }
    return HttpResponse(template.render(context, request))

def location(request):
    mypokemon = Pokemon.objects.all().values()
    myweakness = Weakness.objects.all().values()
    mywildencounters = Wildencounter.objects.all().values()
    mylocations = Location.objects.all().values()
    location_pokemon_map = {}

    mytrainers = []
    mytrainerlocs = []
    for t_id, t_name in zip(Trainer.objects.values_list('t_id', flat=True), Trainer.objects.values_list('t_name', flat=True)):
        pkn = []
        pk = []
        if getTrainer(t_id) != []:
            loc = getTrainer(t_id)[0][0]
        else:
            loc = -1
        if getTrainerKVers(t_id) != []:
            k = (getTrainerKVers(t_id))
            for m in k:
                pk.append(m)
            #pk = getTrainerKVers(t_id)[0]
        for p in pk:
            if getPokemon(p[0]) != []:
                pkn.append(getPokemon(p[0]))
        trainer_info = {
            'trainer_id': t_id,
            'trainer_name': t_name,
            'pokemon_list': pkn,
            'trainer_loc': loc
        }
        mytrainers.append(trainer_info)

    for wildpokemon in mywildencounters:
        location_pokemon_map[wildpokemon['we_pokemonName']] = str(getPokemon(wildpokemon['we_pokemonName']))

    
    categorized_wild_encounters = {}
    for wildpokemon in mywildencounters:
        area = getAreas(wildpokemon['we_pokemonName'], wildpokemon['we_locationID'])
        #print(area)
        area_key = tuple(area)  # Convert list to a tuple for use as a key
        if area_key not in categorized_wild_encounters:
            categorized_wild_encounters[area_key] = []
        categorized_wild_encounters[area_key].append(wildpokemon)
        
    template = loader.get_template('locations.html')
    context = {
        'mypokemon': mypokemon,
        'mylocations': mylocations,
        'mywildencounters': mywildencounters,
        'categorized_wild_encounters': categorized_wild_encounters,
        'myweakness': myweakness,
        'location_pokemon_map': location_pokemon_map,
          'mytrainers': mytrainers,
          'mytrainerlocs': mytrainerlocs,
    }
    return HttpResponse(template.render(context, request))

def trainer(request):
    trainers = Trainer.objects.all().values()
    trainer_data = []

    for trainer in trainers:
        pokemon = getTrainerKVers(trainer["t_id"])
        pokemon_ids = getPokemonIDS(trainer["t_id"])
        
        # Zipping the names and IDs together before adding to the data
        zipped_pokemon_data = zip(pokemon, pokemon_ids)
        
        trainer_data.append({'trainer': trainer, 'pokemon_data': zipped_pokemon_data})
    
    return render(request, 'trainer.html', {'trainer_data': trainer_data})

def pokemon_card(request, pokemon_name):
    # Retrieve the Pokémon details based on the pokemon_name
    # You'll need to query your database here to get the relevant Pokémon information
    # Example: pokemon = Pokemon.objects.get(p_name=pokemon_name)

    # Replace the placeholder with the actual Pokémon data
    pkmen = Pokemon.objects.all().values()
    for pk in pkmen:
        #if(pk.get("p_name",) == pokemon_name[2:len(pokemon_name) - 3]):
        if(pk.get("p_name",) == pokemon_name):
            p_id= pk.get("p_id",)
            p_HP = pk.get("p_hp",)
            p_Attack = pk.get("p_attack",)
            p_Defense = pk.get("p_defense",)
            p_SpecialAttack = pk.get("p_specialattack",)
            p_SpecialDefense = pk.get("p_specialdefense",)
            p_Speed = pk.get("p_speed",)
            p_type1 = pk.get("p_type1",)
            p_type2 = pk.get("p_type2",)
            p_height = pk.get("p_height",)
            p_weight = pk.get("p_weight",)
            p_gender_ratio_mf = pk.get("p_gender_ratio_mf",)
            p_capture_rate = pk.get("p_capture_rate",)
            locations = getLocations(pk.get("p_name"))

     
    pokemon = {
        'p_name': pokemon_name,
        'p_type1': p_type1,
        'p_type2': p_type2,
        'p_height': p_height,
        'p_weight': p_weight,
        'p_gender_ratio_mf': p_gender_ratio_mf,
        'p_capture_rate': p_capture_rate,
        'p_HP': p_HP,
        'p_Attack': p_Attack,
        'p_Defense': p_Defense,
        'p_SpecialAttack': p_SpecialAttack,
        'p_SpecialDefense': p_SpecialDefense,
        'p_Speed': p_Speed,
        'p_id': p_id,
        'locations': locations,
    }

    context = {'pokemon': pokemon}
    return render(request, 'pokemon_card.html', context)

def trainer_card(request, trainer_name):
    
    trainers = Trainer.objects.all().values()
    for trainer in trainers:
        pokemon = getTrainerKVers(trainer["t_id"])
        pokemon_ids = getPokemonIDS(trainer["t_id"])
        zipped_pokemon_data = zip(pokemon, pokemon_ids)
        trainer['Pokemon'] = zipped_pokemon_data
    t_id = 0
    print(trainer_name)
    trainerz = Trainer.objects.all().values()
    for t in trainerz:
        if(t.get("t_name",) == trainer_name):
            t_id = t.get("t_id",)
            

     
    trainer = {
        't_name': trainer_name,
        't_id': t_id,
    }

    context = {'trainer': trainer,
               'trainers': trainers,}
    return render(request, 'trainer_card.html', context)

def pokemon_cardT(request, pokemon_name):
    # Retrieve the Pokémon details based on the pokemon_name
    # You'll need to query your database here to get the relevant Pokémon information
    # Example: pokemon = Pokemon.objects.get(p_name=pokemon_name)

    # Replace the placeholder with the actual Pokémon data
    p_id = 0
    p_type1 = 0
    p_type2 = 0
    p_height = 0
    p_weight = 0
    p_gender_ratio_mf = 0
    p_capture_rate = 0
    p_HP = 0
    p_Attack = 0
    p_Defense = 0
    p_SpecialAttack = 0
    p_SpecialDefense = 0
    p_Speed = 0
    ran =  Trainer.objects.values_list('t_id', flat=True)

    pkmen = Pokemon.objects.all().values()
    for pk in pkmen:
        #if(pk.get("p_name",) == pokemon_name[2:len(pokemon_name) - 3]):
        if(pk.get("p_name",) == pokemon_name):
            p_id= pk.get("p_id",)
            p_type1 = pk.get("p_type1",)
            p_type2 = pk.get("p_type2",)
            p_height = pk.get("p_height",)
            p_weight = pk.get("p_weight",)
            p_gender_ratio_mf = pk.get("p_gender_ratio_mf",)
            p_capture_rate = pk.get("p_capture_rate",)
            p_HP = pk.get("p_HP",)
            p_Attack = pk.get("p_Attack",)
            p_Defense = pk.get("p_Defense",)
            p_SpecialAttack = pk.get("p_SpecialAttack",)
            p_SpecialDefense = pk.get("p_SpecialDefense",)
            p_Speed = pk.get("p_Speed",)
            

     
    pokemon = {
        'p_name': pokemon_name,
        'p_type1': p_type1,
        'p_type2': p_type2,
        'p_height': p_height,
        'p_weight': p_weight,
        'p_gender_ratio_mf': p_gender_ratio_mf,
        'p_capture_rate': p_capture_rate,
        'p_HP': p_HP,
        'p_attack': p_Attack,
        'p_defense': p_Defense,
        'p_specialattack': p_SpecialAttack,
        'p_specialdefense': p_SpecialDefense,
        'p_speed': p_Speed,
        'p_id': p_id,
        'r': ran
    }

    context = {'pokemon': pokemon}
    return render(request, 'pokemon_cardT.html', context)

def teams(request):
   
    mytrainers = Trainer.objects.all().values()
    mytrainers = []
    trainerz = Trainer.objects.all().values()
    trainerz = []
    for t_id, t_name in zip(Trainer.objects.values_list('t_id', flat=True), Trainer.objects.values_list('t_name', flat=True)):
        if t_id > 999:
            pkn = []
            pk = []
            if getTrainerKVers(t_id) != []:
                k = (getTrainerKVers(t_id))
                for m in k:
                    pk.append(m)
            for p in pk:
                pkn.append(getPokemon(p[0]))
            trainer_info = {
                'trainer_id': t_id,
                'trainer_name': t_name,
                'pokemon_list': pkn,
            }
            trainerz.append(trainer_info)
    print(trainerz)

    mytrainers.append(trainer_info)
    template = loader.get_template('teams.html')
    context = {
        'mytrainers': mytrainers,
        'trainerz'  : trainerz
    }
    return HttpResponse(template.render(context, request))

def create_new_team(request):
    # You can add logic here to handle the creation of a new team
    # For example, calling the addTrainer script
    trainerid = addPlayer('ji',6)
    # You may want to redirect the user to the main page or trainer page after creating the team
    template = loader.get_template('create_new_team.html')
    pokemon = Pokemon.objects.all().values()
    items = Item.objects.all().values_list('i_name', flat=True)
    its = Item.objects.all().values()
    moves = Moves.objects.all().values()
    movestable = Movetable.objects.all().values()
    newmoves = []
    count = 0
    for i in moves:
        count = count+1
        if(count > 10):
            break
        newmoves.append(i)
    levels = Item.objects.all().values_list('i_id', flat=True)

    moves = newmoves
    context = {'pokemon': pokemon,
               'items' : items,
               'moves' : moves,
               'movestable' : movestable,
               'levels' : levels,
               'its' : its,
               'trainerid' : trainerid
               }
    return render(request, 'create_new_team.html', context)

def edit_team(request):
    # You can add logic here to handle the creation of a new team
    # For example, calling the addTrainer script
    # You may want to redirect the user to the main page or trainer page after creating the team
    trainer_id = request.GET.get('trainer_id', None)
    print("HERE IS ID",trainer_id)
    template = loader.get_template('edit_team.html')
    pokemon = Pokemon.objects.all().values()
    items = Item.objects.all().values_list('i_name', flat=True)
    its = Item.objects.all().values()
    moves = Moves.objects.all().values()
    movestable = Movetable.objects.all().values()
    newmoves = []
    count = 0
    for i in moves:
        count = count+1
        if(count > 10):
            break
        newmoves.append(i)
    levels = Item.objects.all().values_list('i_id', flat=True)

    moves = newmoves
    context = {'pokemon': pokemon,
               'items' : items,
               'moves' : moves,
               'movestable' : movestable,
               'levels' : levels,
               'its' : its,
               'trainerid' : trainer_id
               }
    return render(request, 'edit_team.html', context)

def edit_pokemon(request, pokemon_id, trainer_id):
    # Get the Pokemon ID from the request's GET parameters
    pokemon = Pokemon.objects.all().values()

    items = Item.objects.all().values_list('i_name', flat=True)
    its = Item.objects.all().values()
    moves = Moves.objects.all().values()
    movestable = Movetable.objects.all().values()
    newmoves = []
    count = 0
    for i in moves:
        count = count + 1
        if count > 10:
            break
        newmoves.append(i)
    levels = Item.objects.all().values_list('i_id', flat=True)

    moves = newmoves

    # Prepare the context to be passed to the template
    context = {
        'pokemon': pokemon,
        'items': items,
        'moves': moves,
        'movestable': movestable,
        'levels': levels,
        'its': its,
        'pokemon_id': pokemon_id,
        'trainerid': trainer_id
    }

    # Render the edit_pokemon.html template with the context
    return render(request, 'edit_pokemon.html', context)


def add_new_pokemon(request):
    all_pokemons = Pokemon.objects.all().values()

    context = {
        'all_pokemons': all_pokemons,
        
    }
    return (render(context, request))


def activate_moves(request, selected_pokemon_id):
    # Call your Python script and pass the selected_pokemon_id
    result = Pokemon.objects.all().values()
    result = getMoves(selected_pokemon_id)
    names = []
    for e in result:
        names.append(e)
    
    #print(selected_pokemon_id)
    # You can customize the response data based on your needs
    context = {
        'message': result,
        'result': result,
        'names': names
    }

    return JsonResponse(context)


def add_trainer_pokemon(request, pokemon_id, selectMove1, selectMove2, selectMove3, selectMove4, selectedLevel, trainerId, selectedItem):
    # Your logic to add the trainer's Pokemon with the given ID and moves
    # ...

    result = []
    result.append(pokemon_id)
    result.append(selectMove1)
    result.append(selectMove2)
    result.append(selectMove3)
    result.append(selectMove4)
    result.append(selectedLevel)
    result.append(trainerId)
    result.append(selectedItem)
    addTrainerPokemon(pokemon_id, trainerId, getMoveIDFromName(selectMove1), getMoveIDFromName(selectMove2), getMoveIDFromName(selectMove3), getMoveIDFromName(selectMove4), selectedItem, selectedLevel)
    print(result)
    print("If that didnt work")
    # Assuming success, return a JSON response
    response_data = {
        'message': result,
    }
    return JsonResponse(response_data)

def update_trainer_pokemon(request, pokemon_id, selectMove1, selectMove2, selectMove3, selectMove4, selectedLevel, trainerId, selectedItem):
    # Your logic to add the trainer's Pokemon with the given ID and moves
    # ...

    result = []
    result.append(pokemon_id)
    result.append(selectMove1)
    result.append(selectMove2)
    result.append(selectMove3)
    result.append(selectMove4)
    result.append(selectedLevel)
    result.append(trainerId)
    result.append(selectedItem)
    updatePokemon(pokemon_id, trainerId, selectMove1, selectMove2, selectMove3, selectMove4, selectedItem, selectedLevel)
    print(result)
    print("If that didnt work")
    # Assuming success, return a JSON response
    response_data = {
        'message': result,
    }
    return JsonResponse(response_data)

def kill_trainer_pokemon(request, pokemon_id, selectMove1, selectMove2, selectMove3, selectMove4, selectedLevel, trainerId, selectedItem):
    # Your logic to add the trainer's Pokemon with the given ID and moves
    # ...

    result = []
    result.append(pokemon_id)
    result.append(selectMove1)
    result.append(selectMove2)
    result.append(selectMove3)
    result.append(selectMove4)
    result.append(selectedLevel)
    result.append(trainerId)
    result.append(selectedItem)
    softDel(pokemon_id, trainerId, selectMove1, selectMove2, selectMove3, selectMove4, selectedItem, selectedLevel)
    print("that shit dead i think")
    # Assuming success, return a JSON response
    response_data = {
        'message': result,
    }
    return JsonResponse(response_data)