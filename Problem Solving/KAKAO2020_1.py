def solution(s):
    answer = len(s)
    for i in range(1, len(s)):
        ans = ''
        k = 0
        cur = 0
        flag = False
        while cur < len(s) - i:
            flag = False
            tmp = s[cur:cur + i]
            cur += i
            rep = 1
            for k in range(cur, len(s), i):
                if tmp == s[k:k + i]:
                    rep += 1
                else:
                    flag = True
                    break
            cur = k
            if rep <= 1:
                ans += tmp
            else:
                ans += str(rep) + tmp
        if flag == True:
            ans += s[cur:]
        if len(ans) < answer:
            answer = len(ans)
    return answer