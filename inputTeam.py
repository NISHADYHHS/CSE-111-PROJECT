import sqlite3

def addPlayer(name, team_cnt):
    con = sqlite3.connect("pokemon.db")
    cur = con.cursor()
    cur.execute("SELECT COUNT(t_id) FROM Trainer WHERE t_id > 1000")
    numbertoadd = str(cur.fetchall())
    cur.execute("SELECT MAX(t_id) FROM Trainer")
    max = cur.fetchall()[0][0]
    thingtoadd = 0
    if(max < 1000):
        thingtoadd = 474
    else:
        thingtoadd = 1
    data = [
        (max + thingtoadd, 'MyPlayer' + numbertoadd, 1, 1, team_cnt, 1, 'brock.png')
    ]
    cur.executemany("INSERT INTO Trainer VALUES(?, ?, ?, ?, ?, ?, ?)", data)
    con.commit()
    return (max + thingtoadd)

def getMoveIDFromName(movename):
    con = sqlite3.connect("pokemon.db")
    cur = con.cursor()
    cur.execute(f"SELECT m_id FROM Moves WHERE m_name = '{movename}' ")
    id = cur.fetchall()[0][0]
    return id


def getLocations(p_name):
    con = sqlite3.connect("pokemon.db")
    cur = con.cursor()
    cur.execute("select DISTINCT location.l_name from WildEncounter inner join location on location.l_id = WildEncounter.we_locationID where WildEncounter.we_pokemonName = '" + str(p_name) + "'")
    id = cur.fetchall()
    return id

def updatePokemon(p_id,trainer_id, p_move1ID ,p_move2ID ,p_move3ID ,p_move4ID ,tp_itemName ,tp_level):
    con = sqlite3.connect("pokemon.db")
    cur = con.cursor()
    cur.execute(f"UPDATE TrainerPokemon SET p_move1ID = '{p_move1ID}'WHERE p_trainerID = '{trainer_id}' AND p_id = '{p_id}'")
    cur.execute(f"UPDATE TrainerPokemon SET p_move2ID = '{p_move2ID}' WHERE p_trainerID = '{trainer_id}'AND p_id = '{p_id}'")
    cur.execute(f"UPDATE TrainerPokemon SET p_move3ID = '{p_move3ID}' WHERE p_trainerID = '{trainer_id}' AND p_id = '{p_id}'")
    cur.execute(f"UPDATE TrainerPokemon SET p_move4ID = '{p_move4ID}'    WHERE p_trainerID = '{trainer_id}' AND p_id = '{p_id}'")
    cur.execute(f"UPDATE TrainerPokemon SET tp_itemName = '{tp_itemName}'   WHERE p_trainerID = '{trainer_id}' AND p_id = '{p_id}'")
    cur.execute(f"UPDATE TrainerPokemon SET tp_level = '{tp_level}'   WHERE p_trainerID = '{trainer_id}' AND p_id = '{p_id}'")
    con.commit()

def killPokemon(trainer_id,p_id,p_move1ID,p_move2ID,p_move3ID,p_move4ID,tp_itemName,tp_level):
    con = sqlite3.connect("pokemon.db")
    cur = con.cursor()
    cur.execute(f"DELETE FROM TrainerPokemon WHERE p_id = '{p_id}' AND p_trainerID = '{trainer_id}' AND p_move1ID = '{p_move1ID}' AND p_move2ID = '{p_move2ID}' AND p_move3ID = '{p_move3ID}' AND p_move4ID = '{p_move4ID}' AND tp_itemName = '{tp_itemName} AND tp_level = '{tp_level}'")
    print(trainer_id, p_id,p_move1ID,p_move2ID,p_move3ID,p_move4ID,tp_itemName,tp_level )
    con.commit()

def softDel(p_id,trainer_id,p_move1ID,p_move2ID,p_move3ID,p_move4ID,tp_itemName,tp_level):
    con = sqlite3.connect("pokemon.db")
    cur = con.cursor()
    cur.execute(f"DELETE FROM TrainerPokemon WHERE p_id = '{p_id}' AND p_trainerID = '{trainer_id}'")
    
    con.commit()    


def addTrainerPokemon(p_id, p_trainerID, p_move1ID, p_move2ID, p_move3ID, p_move4ID, tp_itemName, tp_level):
    con = sqlite3.connect("pokemon.db")
    cur = con.cursor()
    cur.execute("SELECT a_id FROM Ability INNER JOIN Pokemon ON Ability.a_id = Pokemon.p_ability1 WHERE p_id = '" + str(p_id) + "'")
    #ab = cur.fetchall()[0][0]
    data = [
        (p_id, "Torrent" , p_trainerID, p_move1ID, p_move2ID, p_move3ID, p_move4ID, tp_itemName, tp_level)
    ]
    cur.executemany("INSERT INTO TrainerPokemon VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?)", data)
    con.commit()


def addPokemon(name, id, moves):
    con = sqlite3.connect("pokemon.db")
    cur = con.cursor()
    cur.execute("SELECT p_id FROM Pokemon WHERE p_name = '" + str(name) + "'")
    mon = cur.fetchall()[0][0]
    moves = setMoves(moves)
    data = [
        (mon, 1, id, moves[0], moves[1], moves[2], moves[3])
    ]
    cur.executemany("INSERT INTO TrainerPokemon VALUES(?, ?, ?, ?, ?, ?, ?)", data)
    con.commit()
    addCount(id)

def addTeam(names, moves, id):
    print(moves[0])
    con = sqlite3.connect("pokemon.db")
    cur = con.cursor()
    for i in range(len(names)):
        moves[i] = setMoves(moves[i])
        addPokemon (names[i], id, moves[i])

def getPName(p_id):
    con = sqlite3.connect("pokemon.db")
    cur = con.cursor()
    cur.execute("SELECT p_name FROM Pokemon WHERE p_id = '" + str(p_id) + "'")
    moves = cur.fetchall()
    #con.commit()
    return moves

def getPokemonIDS(trainer):
    con = sqlite3.connect("pokemon.db")
    cur = con.cursor()
    cur.execute("SELECT Pokemon.p_id FROM Trainer Inner JOIN TrainerPokemon ON TrainerPokemon.p_trainerID = Trainer.t_id INNER JOIN Pokemon ON Pokemon.p_id = TrainerPokemon.p_id WHERE t_id = '" + str(trainer) + "'")
    names = cur.fetchall()
    #con.commit()
    return names

def getMoves(p_id):
    con = sqlite3.connect("pokemon.db")
    cur = con.cursor()
    cur.execute("SELECT Moves.m_name FROM Moves INNER JOIN MoveTable ON Moves.m_id = MoveTable.mt_moveID INNER JOIN Pokemon ON MoveTable.mt_pokemonID = Pokemon.p_id WHERE p_id = '" + str(p_id) + "'")
    moves = cur.fetchall()
    #con.commit()
    return moves


def getAreas(p_name, loc_id):
    con = sqlite3.connect("pokemon.db")
    cur = con.cursor()
    cur.execute("select we_area from WildEncounter where we_pokemonName = '" + str(p_name) + "' and we_locationID = " + str(loc_id))
    areas = cur.fetchall()
    return areas
    
    
    
'''
    con = sqlite3.connect("pokemon.db")
    cur = con.cursor()
    cur.execute("SELECT t_team_pokemon_count FROM Trainer WHERE t_id = '" + str(id) + "'")

    amt = cur.fetchall()[0][0]
    for i in range (0, amt):
        poke = input()
        moves = []
        moveamt = input('How many moves?')
        for i in range(0, 4):
            if i <= int(moveamt) - 1:
                moves.append(getMove(input()))
            else:
                moves.append(None)
        addPokemon(poke, id, moves)
        '''

def setMoves(moves):
    for i in range(4):
        if i < len(moves):
            moves[i] = getMove(moves[i])
        else:
            moves.append(None)
    return moves


def getEnemyTrainer(t_id):
    con = sqlite3.connect("pokemon.db")
    cur = con.cursor()
    cur.execute("SELECT * FROM Trainer INNER JOIN Location ON Location.l_id = Trainer.t_id Inner JOIN TrainerPokemon ON TrainerPokemon.p_trainerID = Trainer.t_id WHERE t_id = 2")
    data = cur.fetchall()
    return data

def getTrainer(t_id):
    con = sqlite3.connect("pokemon.db")
    cur = con.cursor()
    cur.execute("SELECT TrainerLocation.tl_locationID FROM TrainerLocation INNER JOIN Trainer ON TrainerLocation.tl_trainerID = Trainer.t_id WHERE t_id = '" + str(t_id) + "'")
    data = cur.fetchall()
    return data

def getTrainerN(t_id):
    con = sqlite3.connect("pokemon.db")
    cur = con.cursor()
    cur.execute("SELECT p_name FROM Pokemon INNER JOIN TrainerPokemon ON Pokemon.p_id = TrainerPokemon.p_id INNER JOIN Trainer ON TrainerPokemon.p_trainerID = Trainer.t_id WHERE t_id = '" + str(t_id) + "'")
    data = cur.fetchall()
    return data

def getTrainerKVers(t_id):
    con = sqlite3.connect("pokemon.db")
    cur = con.cursor()
    cur.execute("SELECT p_name FROM Trainer Inner JOIN TrainerPokemon ON TrainerPokemon.p_trainerID = Trainer.t_id INNER JOIN Pokemon ON Pokemon.p_id = TrainerPokemon.p_id WHERE t_id = '" + str(t_id) + "'")
    data = cur.fetchall()
    return data

def getPokeInfo(p_id):
    con = sqlite3.connect("pokemon.db")
    cur = con.cursor()
    cur.execute("SELECT * FROM Pokemon INNER JOIN WildEncounter ON WildEncounter.we_pokemonID = Pokemon.p_id INNER JOIN Location ON Location.l_id = we_LocationID WHERE Pokemon.p_id = '" + str(p_id) + "'")
    #cur.execute("SELECT * FROM Pokemon WHERE Pokemon.p_id = '" + str(p_id) + "'")
    data = cur.fetchall()
    return data

def getPokemonLocation(p_id):
    con = sqlite3.connect("pokemon.db")
    cur = con.cursor()
    cur.execute("SELECT Pokemon.p_name, Location.l_name FROM Pokemon INNER JOIN WildEncounter ON WildEncounter.we_pokemonID = Pokemon.p_id INNER JOIN Location ON Location.l_id = we_LocationID WHERE Pokemon.p_id = '" + str(p_id) + "'")
    #cur.execute("SELECT * FROM Pokemon WHERE Pokemon.p_id = '" + str(p_id) + "'")
    data = cur.fetchall()
    return data

def getLocationID(l_name):
    con = sqlite3.connect("pokemon.db")
    cur = con.cursor()
    cur.execute("SELECT l_id FROM Location WHERE l_name = '" + str(l_name) + "'")
    #cur.execute("SELECT * FROM Pokemon WHERE Pokemon.p_id = '" + str(p_id) + "'")
    data = cur.fetchall()
    return data[0]





def getBadgeCount(t_id):
    con = sqlite3.connect("pokemon.db")
    cur = con.cursor()
    cur.execute("SELECT t_badge_count FROM Trainer WHERE t_id = '" + str(t_id) + "'")
    ability = cur.fetchall()[0][0]
    return ability

def getTrainerLocation(t_id):
    con = sqlite3.connect("pokemon.db")
    cur = con.cursor()
    cur.execute("SELECT t_locationID FROM Trainer WHERE t_id = '" + str(t_id) + "'")
    location = cur.fetchall()[0][0]
    return location

def getDescription(p_id):
    con = sqlite3.connect("pokemon.db")
    cur = con.cursor()
    cur.execute("SELECT p_description FROM Pokemon WHERE p_id = '" + str(p_id) + "'")
    ability = cur.fetchall()[0][0]
    return ability

def getAbility(a_id):
    con = sqlite3.connect("pokemon.db")
    cur = con.cursor()
    cur.execute("SELECT a_name FROM Ability WHERE a_id = '" + str(a_id) + "'")
    ability = cur.fetchall()[0][0]
    return ability

def getTrainers(t_name):
    con = sqlite3.connect("pokemon.db")
    cur = con.cursor()
    cur.execute("SELECT t_id FROM Trainer WHERE t_name = '" + str(t_name) + "'")
    trainers = cur.fetchall()
    return trainers

def getTrainerNames(t_id):
    con = sqlite3.connect("pokemon.db")
    cur = con.cursor()
    cur.execute("SELECT t_name FROM Trainer WHERE t_id = '" + str(t_id) + "'")
    trainer = cur.fetchall()[0][0]
    return trainer

def getMove(name):
    con = sqlite3.connect("pokemon.db")
    cur = con.cursor()
    cur.execute("SELECT m_id FROM Moves WHERE m_name = '" + str(name) + "'")
    id = cur.fetchall()[0][0]
    return id

def getPokemon(name):
    con = sqlite3.connect("pokemon.db")
    cur = con.cursor()
    cur.execute("SELECT p_id FROM Pokemon WHERE p_name = '" + str(name) + "'")
    mon = cur.fetchone()
    if mon == None:
        return 0
    else:
        return int(mon[0])


def deletePokemon(t_id, poke):
    con = sqlite3.connect("pokemon.db")
    cur = con.cursor()
    p_id = getPokemon(poke)
    cur.execute("DELETE FROM TrainerPokemon WHERE p_trainerID = '" + str(t_id) + "'" + " AND p_id = '" + str(p_id) + "'")
    con.commit()
    subCount(t_id)

def deleteTeam(t_id):
    con = sqlite3.connect("pokemon.db")

    cur = con.cursor()
    cur.execute("DELETE FROM TrainerPokemon WHERE p_trainerID = '" + str(t_id) + "'")
    con.commit()

def hasPokemon(name, t_id):
    p_id = getPokemon(name)
    con = sqlite3.connect("pokemon.db")
    cur = con.cursor()
    cur.execute("SELECT * FROM TrainerPokemon WHERE p_trainerID = '" + str(t_id) + "'" + " AND p_id = '" + str(p_id) + "'")
    con.commit()
    return len(cur.fetchall()) > 0

def replacePokemon(name, poke, id, moves):
    moveamt = len(moves)
    for i in range(0, 4):
            if i <= int(moveamt) - 1:
                moves[i] = (getMove(moves[i]))
            else:
                moves.append(None)
    if hasPokemon(poke, id):
        deletePokemon(id, poke)
        addPokemon(name, id, moves)
    else:
        print("not found\n")

def addCount(id):
    con = sqlite3.connect("pokemon.db")
    cur = con.cursor()
    cur.execute("UPDATE Trainer SET t_team_pokemon_count = t_team_pokemon_count + 1 WHERE t_id = '" + str(id) + "'")
    con.commit()

def subCount(id):
    con = sqlite3.connect("pokemon.db")
    cur = con.cursor()
    cur.execute("UPDATE Trainer SET t_team_pokemon_count = t_team_pokemon_count - 1 WHERE t_id = '" + str(id) + "'")
    con.commit()

def printLine(l_name, p_name, catchRate):
    n = getPokemon(p_name)
    l = getLocationID(l_name)
    print(n,"|",l,"|",catchRate)

if __name__ == "__main__":
    #team_cnt = input()
    #addPlayer(name, team_cnt)
    #addTeam(input("enter id"))location name catch rate
    
    print(getMoveIDFromName("Outrage"))
