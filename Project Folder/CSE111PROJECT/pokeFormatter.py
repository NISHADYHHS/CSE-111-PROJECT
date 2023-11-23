def getvalues(poke):
    info = []
    poke = poke.split('\t')
    info.append(poke[0])
    info.append(poke[1])
    info.append(0)
    info.append(0)
    info.append(0)
    info.append(poke[9])
    type2 = poke[10]
    if type2 == "":
        type2 = None
    info.append(type2)
    info.append(0)
    info.append(poke[15])
    info.append(poke[12])
    ability = poke[13]
    if ability == '':
        ability = "NULL"
    info.append(ability)
    if ability == '':
        ability = "NULL"
    info.append(ability)
    gender = poke[21]
    if gender == 'Neutral':
        gender = '0.5'
    elif gender == "None":
        gender = "NULL"
    else:
        if gender[0] == "M":
            gender = (float(gender.split("%")[0][3:]) / 100)
        else:
            gender = 1 - (float(gender.split("%")[0][3:]) / 100)

    info.append(gender)
    info.append(poke[-1])
    info.append(poke[2])
    info.append(poke[3])
    info.append(poke[4])
    info.append(poke[5])
    info.append(poke[6])
    info.append(poke[7])
    info.append(0)
    info.append(0)
    info.append(0)
    info.append(0)
    info.append(0)
    mystring = ''
    mystring += str(info[0])
    for i in range (1, len(info)):
        mystring += "|" + str(info[i])
    print(mystring)
    try:
        with open("Pokemon.tbl", 'a') as file:
            # Read the entire contents of the file
            file.write(mystring + '\n')
            file.close()
    except FileNotFoundError:
        print(f"File '{file_path}' not found.")
        return None
    except Exception as e:
        print(f"An error occurred: {e}")
        return None


def read_text_file(file_path):
    try:
        with open(file_path, 'r') as file:
            # Read the entire contents of the file
            file_contents = file.read()
            for poke in file_contents.split('\n'):
                getvalues(poke)
            pokemon = []
            
            return file_contents
    except FileNotFoundError:
        print(f"File '{file_path}' not found.")
        return None
    except Exception as e:
        print(f"An error occurred: {e}")
        return None

# Example usage:
file_path = 'pokemonList.txt'  # Replace with your file path
content = read_text_file(file_path)
#if content:
    #print(f"Content of '{file_path}':\n{content}")
