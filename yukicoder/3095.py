def octal(n: int) -> str:
    if n < 8:
        return str(n)
    return octal(n // 8) + str(n % 8)

n = 720493827591246930338514147961993877046372705745224529216897553100355225556660043471729777334356378706709635607372948
# print(octal(n))
# 2222222222222226022222222137024333341260333333331370334334333333412602222222213702222412603333333313703334241260222222221370222224

# A language to Brainfuck
# +++++++++++++++[>++++++++<-]>+.----.<+[>--------<-]>--.--.------.<+[>++++++++<-]>++++.<+[>--------<-]>---.+.<+[>++++++++<-]>+++++.

print('yukicoder')