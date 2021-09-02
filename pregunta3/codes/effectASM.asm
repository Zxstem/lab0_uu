global effectASM
    section .text
effectASM:
    ; rdi << *A
    ; rsi << *Casm
    ; rdx << imgSize
    xorpd xmm1, xmm1
    xorpd xmm3, xmm3
    pcmpeqd xmm2, xmm2  ; xnor xmm2, xmm2
    cmp rdx, 0
    je final

bucle:  
    movq xmm1, [rdi+8]  ; load last 8 chars   
    pslldq xmm1, 8      ; shift left 8 bytes
    movq xmm3, [rdi]    ; load first 8 chars
    por xmm1, xmm3      ; load 16 chars to xmm1

    pxor xmm1, xmm2     ; ~A[i:i+16]

    ; saving LIFO from xmm1
    movq [rsi], xmm1
    psrldq xmm1, 8      ; shift right
    movq [rsi+8], xmm1
    
    add rdi, 16
    add rsi, 16
    sub rdx, 16
    jnz bucle

final:
    ret