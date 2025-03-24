from collections import Counter

def solution(nums):
    pokemons = dict(Counter(nums))

    return min(len(pokemons), len(nums) // 2)