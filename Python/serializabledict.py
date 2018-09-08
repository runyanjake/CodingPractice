# @author jake runyan
# prompt: make a serializable dictionary using json

import json

class Object:
    def __init__(self, n):
        self.name = n
    def __str__(self):
        return (str(self.name) + " The Object")

class Dictionary(Object):
    def __init__(self, n):
        self.name = n.replace(" ", "").replace("\n", "")
        self.keys = {} #key->idx
        self.vals = [] #idx->value
        self.size = 0

    def insert(self, key, val):
        if key in self.keys:
            self.vals[self.keys[key]] = val
        else:
            self.vals.append(val)
            self.keys[key] = len(self.vals)-1
            self.size = self.size + 1

    def delete(self, key):
        if key in self.keys:
            del self.keys[key]
            self.size = self.size -1

    def get(self, key):
        if key in self.keys:
            return self.vals[self.keys[key]]
        return None

    def length(self):
        return self.size

    def save(self):
        jsondata = {}
        data = []
        for key in self.keys:
            tmp = {}
            tmp[key] = self.vals[self.keys[key]]
            data.append(tmp)
        jsondata["name"] = self.name
        jsondata["data"] = data
        filename = self.name.replace(" ", "").replace("\n", "") + ".json"
        with open(str(filename), "w") as jsonfile:
            json.dump(jsondata, jsonfile, indent=4)

    @classmethod
    def load(cls, name):
        filename = name.replace(" ", "").replace("\n", "")
        try:
            with open(filename + ".json", 'r') as jsonfile:
                data = json.load(jsonfile)
                newDict =  Dictionary(data["name"])
                for entry in data["data"]:
                    for e in entry:
                        newDict.insert(e, entry[e])
                return newDict
        except(Exception):
            return None
        

    def __str__(self):
        stng = (str(self.name) + " The Dictionary: {")
        first = True
        for a in self.keys:
            if first:
                stng = stng + str(a) + ": " + str(self.vals[self.keys[a]])
                first = False
            else:
                stng = stng +  ", " + str(a) + ": " + str(self.vals[self.keys[a]])
        stng = stng + "}"
        return stng
        