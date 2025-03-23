G={
    'A':['M','Q'],
    'M':['A','Z','C'],
    'Q':['A','Y','R'],
    'Z':['M'],
    'C':['M'],
    'Y':['Q'],
    'R':['Q']
    
}

def BFT(G,start):
    stack=[]
    visited=[]
    stack.append(start)
    while(stack):
        poppedVertex=stack.pop(0)
        visited.append(poppedVertex)
        for chimeki in G[poppedVertex]:
            if chimeki not in visited and chimeki not in stack:
                stack.append(chimeki)
    return visited


start='A'
print(BFT(G,start))