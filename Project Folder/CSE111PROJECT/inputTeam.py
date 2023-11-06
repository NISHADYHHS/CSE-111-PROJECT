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
    data = [
        (mon, 1, id, moves[0], moves[1], moves[2], moves[3])
    ]
    cur.executemany("INSERT INTO TrainerPokemon VALUES(?, ?, ?, ?, ?, ?, ?)", data)
    con.commit()

def addTeam(id):
    con = sqlite3.connect("pokemon.db")
    cur = con.cursor()
    cur.execute("SELECT t_team_pokemon_count FROM Trainer WHERE t_id = '" + str(id) + "'")
    print(amt)
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
    con.commit()  # Remember to commit the transaction after executing INSERT.

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

if __name__ == "__main__":
    #name = input()
    #team_cnt = input()
    #addPlayer(name, team_cnt)
    #addTeam(input("enter id"))
    replacePokemon('Pikachu', 'Bulbasaur', 7, ['Razor Leaf', 'Thunderbolt'])
