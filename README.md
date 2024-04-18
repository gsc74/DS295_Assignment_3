# DS295 Assignment 3 Verification

```bash
# Get code and make it run
git clone https://github.com/gsc74/DS295_Assignment_3.git
cd DS295_Assignment_3
make

# Generate input.bin
./Generate

# Generate output.bin
./Sort
```

## Instructions
 1) Generate the output.bin using your code and rename to output_test.bin
 2) Generate the output using our code (i.e. Sort) and  get output.bin
 3) Use `diff output.bin output_test.bin` to check difference between the ouput. [This is expected to be NULL]

## Evaluation
 1) Establish the correction of the ouputs.
 2) Show the speedup of your parallel code against your sequential code.