def toh( n,fromRod,toRod,auxRod)
  if (n==1):
    print("Move 1st disc from",fromRod ," to ",toRod)
    return
  toh(n-1,fromRod,auxRod,toRod)
  print("Move ",n,"th disc from ",fromRod," to ",toRod)
  toh(n-1,auxRod,toRod,fromRod)

n = int(input())
toh(n,"T1","T2","T3")
    
