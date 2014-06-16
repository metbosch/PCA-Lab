make
echo "EXEC ATOM1"
./ftdock -static ../../../inputs/2pka.parsed -mobile ../../../inputs/5pti.parsed >../outputs/001.out
./ftdock -static ../../../inputs/2pka.parsed -mobile ../../../inputs/5pti.parsed >../outputs/001.out
echo "---------- DIFFS EXEC ATOM1 ----------"
diff ../outputs/001.out ../../../outputs/test1.output
echo "------- ------- ----- -------- -------"

echo "EXEC ATOM2"
./ftdock -static ../../../inputs/1hba.parsed -mobile ../../../inputs/5pti.parsed >../outputs/002.out
./ftdock -static ../../../inputs/1hba.parsed -mobile ../../../inputs/5pti.parsed >../outputs/002.out
echo "---------- DIFFS EXEC ATOM2 ----------"
diff ../outputs/002.out ../../../outputs/test2.output

echo "EXEC ATOM3"
./ftdock -static ../../../inputs/4hhb.parsed -mobile ../../../inputs/5pti.parsed >../outputs/003.out
./ftdock -static ../../../inputs/4hhb.parsed -mobile ../../../inputs/5pti.parsed >../outputs/003.out
echo "---------- DIFFS EXEC ATOM3 ----------"
diff ../outputs/003.out ../../../outputs/test3.output
echo "------- ------- ----- -------- -------"