import sqlite3

def addPlayer(name, team_cnt):
    con = sqlite3.connect("pokemon.db")
    cur = con.cursor()

    cur.execute("SELECT MAX(t_id) FROM Trainer")
    max = cur.fetchall()[0][0]
    data = [
        (max + 1, name, 1, 1, team_cnt, 1, 'brock.png')
    ]
    cur.executemany("INSERT INTO Trainer VALUES(?, ?, ?, ?, ?, ?, ?)", data)
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
    cur.execute("SELECT * FROM Trainer INNER JOIN Location ON Location.l_id = Trainer.t_id Inner JOIN TrainerPokemon ON Pokemon.p_trainerID = Trainer.t_id WHERE Trainer.t_id = '" + str(t_id) + "'")
    data = cur.fetchall()
    return data

def getPokeInfo(p_id):
    con = sqlite3.connect("pokemon.db")
    cur = con.cursor()
    cur.execute("SELECT * FROM Pokemon INNER JOIN Location ON Location.l_id = Pokemon.p_LocationID Inner JOIN Ability ON a_id = p_ability1 WHERE Pokemon.p_id = '" + str(p_id) + "'")
    data = cur.fetchall()
    return data

def getTrainerLocation(t_id):
    con = sqlite3.connect("pokemon.db")
    cur = con.cursor()
    cur.execute("SELECT t_locationID FROM Trainer WHERE t_id = '" + str(t_id) + "'")
    location = cur.fetchall()[0][0]
    return location

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
    mon = cur.fetchall()
    return int(mon[0][0])


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

if __name__ == "__main__":
    #name = input()
    #team_cnt = input()
    #addPlayer(name, team_cnt)
    #addTeam(input("enter id"))
    print(getTrainerLocation(2))