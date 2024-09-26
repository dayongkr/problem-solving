def solution(n, info):
    from copy import deepcopy

    max_diff = 0
    best = [-1]

    def backtrack(idx, arrows_left, lion):
        nonlocal max_diff, best
        if idx == 11:
            if arrows_left > 0:
                lion[10] += arrows_left  # 남은 화살을 0점에 할당
            # 점수 계산
            lion_score = 0
            peach_score = 0
            for i in range(11):
                if info[i] == 0 and lion[i] == 0:
                    continue
                if lion[i] > info[i]:
                    lion_score += 10 - i
                else:
                    peach_score += 10 - i
            diff = lion_score - peach_score
            if diff > 0:
                if diff > max_diff:
                    max_diff = diff
                    best = deepcopy(lion)
                elif diff == max_diff:
                    # 더 낮은 점수를 많이 맞힌 경우 선택
                    for i in range(10, -1, -1):
                        if lion[i] > best[i]:
                            best = deepcopy(lion)
                            break
                        elif lion[i] < best[i]:
                            break
            if arrows_left > 0:
                lion[10] -= arrows_left  # 초기 상태로 복구
            return

        # 옵션 1: 라이언이 현재 점수를 이기기 위해 화살을 할당
        if arrows_left > info[idx]:
            lion[idx] = info[idx] + 1
            backtrack(idx + 1, arrows_left - (info[idx] + 1), lion)
            lion[idx] = 0  # 초기 상태로 복구

        # 옵션 2: 라이언이 현재 점수를 이기지 않음
        backtrack(idx + 1, arrows_left, lion)

    initial_lion = [0] * 11
    backtrack(0, n, initial_lion)

    return best