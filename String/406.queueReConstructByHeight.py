class Solution:
    def reconstructQueue(self, people):
        people.sort(key=lambda p: p[0], reverse=True)
        i = 0
        result = []
        while i < len(people):
            num = people[i][0]
            lo = i
            while i<len(people) and people[i][0] == num:
                i += 1 
            hi = i
            sub_queue = people[lo:hi]
            sub_queue.sort(key=lambda i: i[1])
            for j in sub_queue:
                result.insert(j[1], j)

        return result 
