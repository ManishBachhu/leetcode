class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        //we know integer has 32 bits, so shift one side to left (right half will be filled with zeros) and other side to right (left half side will be filled with zeros) take a logical OR of them and you have swapped right and left side
        n = ( n >> 16 | n << 16);
        //create mask 8bits of 1's then 8bits of 0's then 8bits of 1's and then 8 bits of 0's take logical AND between previous result to get location of 1's, then right shift it by 8 bits. At the same time create opposite mask (starting with 0's) and take logical AND of that and previous result. Combine both results by taking logical OR - you just swapped bits every 8 bits. Continue same pattern by dividing number by 2 previous number used for alternations and shifting (so next mask is alternating bits every 4 and then shift by 4)
        n = ((n & 0b11111111000000001111111100000000) >> 8) | ((n & 0b00000000111111110000000011111111) << 8);
        n = ((n & 0b11110000111100001111000011110000) >> 4) | ((n & 0b00001111000011110000111100001111) << 4);
        n = ((n & 0b11001100110011001100110011001100) >> 2) | ((n & 0b00110011001100110011001100110011) << 2);
        n = ((n & 0b10101010101010101010101010101010) >> 1) | ((n & 0b01010101010101010101010101010101) << 1);
        return n;
    }
};
