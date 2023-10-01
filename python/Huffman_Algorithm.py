import heapq
from collections import defaultdict, Counter

class HuffmanNode:
    def __init__(self, char, freq):
        self.char = char
        self.freq = freq
        self.left = None
        self.right = None

    def __lt__(self, other):
        return self.freq < other.freq

def build_huffman_tree(data):
    char_freq = Counter(data)
    priority_queue = [HuffmanNode(char, freq) for char, freq in char_freq.items()]
    heapq.heapify(priority_queue)

    while len(priority_queue) > 1:
        left_node = heapq.heappop(priority_queue)
        right_node = heapq.heappop(priority_queue)
        internal_node = HuffmanNode(None, left_node.freq + right_node.freq)
        internal_node.left = left_node
        internal_node.right = right_node
        heapq.heappush(priority_queue, internal_node)

    return priority_queue[0]

def build_huffman_codes(node, prefix="", code_map=None):
    if code_map is None:
        code_map = {}

    if node is not None:
        if node.char is not None:
            code_map[node.char] = prefix
        build_huffman_codes(node.left, prefix + "0", code_map)
        build_huffman_codes(node.right, prefix + "1", code_map)

    return code_map

def huffman_encode(data):
    root = build_huffman_tree(data)
    codes = build_huffman_codes(root)
    encoded_data = ''.join(codes[char] for char in data)
    return encoded_data, codes

def huffman_decode(encoded_data, codes):
    decoded_data = ""
    current_code = ""
    
    for bit in encoded_data:
        current_code += bit
        for char, code in codes.items():
            if code == current_code:
                decoded_data += char
                current_code = ""
                break

    return decoded_data

if __name__ == "__main__":
    input_data = input("Enter the text to encode: ")
    encoded_data, huffman_codes = huffman_encode(input_data)
    print(f"Encoded data: {encoded_data}")
    
    decoded_data = huffman_decode(encoded_data, huffman_codes)
    print(f"Decoded data: {decoded_data}")
