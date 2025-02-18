with open("data.csv","w") as file : 
    file.write("1")

with open("data.csv","r") as file : 
    print(file.read())