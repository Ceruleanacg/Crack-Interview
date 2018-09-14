def wordparser(input_lines):

    words = ''.join(input_lines).lower().split()

    char_map = {}
    word_map = {}

    for i in range(ord('a'), ord('z') + 1, 1):
        char_map[i] = 0

    num_word = 0
    for word in words:
        need_continue = False
        if word == '':
            continue
        for char in word:
            if ord(char) not in char_map:
                need_continue = True
                continue
        if need_continue:
            continue
        for char in word:
            char_map[ord(char)] += 1
        num_word += 1
        if word in word_map:
            word_map[word] += 1
        else:
            word_map[word] = 1

    sorted_keys = sorted(word_map)

    result = '{}\n'.format(num_word)
    result += 'words\n'
    for key in sorted_keys:
        result += '{} {}\n'.format(key, word_map[key])
    result += 'letters\n'
    for char in char_map:
        result += '{} {}\n'.format(chr(char), char_map[char])
    return result
