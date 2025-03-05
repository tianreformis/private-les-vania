class Stack: 
    def __init__(self):
        self.stack = []

    def push(self, data):
            self.stack.append(data)
    
    def pop(self):
         if not self.isEmpty():
            return self.stack.pop()
         else:
            return None

    #check apa kosong atau
        
    #return data kalau dia tidak kosong
    def peek(self):
        if not self.isEmpty():
            return self.stack[-1]
        else:
            return None    
    def isEmpty(self):
        return len(self.stack) == 0    
    
    def show(self):
        return self.stack
  
s = Stack()
s.push(10)
s.push(20)
s.push(30)

print(s.show())

print(s.pop())

print(s.show())