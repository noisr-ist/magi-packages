from MAGI import Api

api = Api()
print(int(api.generate(10)["numbers"][0],2)) # Convert binary to decimal
