class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        len1, len2 = len(word1), len(word2)

        if len1 < len2:
            return False

        dict1, dict2 = {}, {}

        for char in word1:
            if char in dict1:
                dict1[char] += 1
            else:
                dict1[char] = 1

        for char in word2:
            if char in dict2:
                dict2[char] += 1
            else:
                dict2[char] = 1
        
        alias = {key: key for key in dict2}

        sorted_dict1 = sorted(dict1.items(), key=lambda x: x[1])
        sorted_dict2 = sorted(dict2.items(), key=lambda x: x[1])

        if len(dict1.keys()) != len(dict2.keys()):
            return False

        for i in range(len(sorted_dict1)):
            key1, value1 = sorted_dict1[i]
            key2, value2 = sorted_dict2[i]
            key2 = alias[key2]

            if value1 != value2:
                return False

            if key1 != key2:
                print(key1, key2)
                if key1 not in alias:
                    return False
                alias[key1], alias[key2] = key2, key1
        
        return True