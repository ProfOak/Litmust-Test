import java.lang.*;
import java.util.*;

public class time2sex {
    public static void main(String[] args) {
        if (args.length != 1) {
            return;
        }

        final int[] SECONDS = {1, 60, 3600};
        int sum = 0;
        List<String> tmp = Arrays.asList(args[0].split(":"));
        int len = tmp.size() > 3 ? 3 : tmp.size();

        // reversing makes it easier to calculate with
        // the correct indices regardless of input length
        Collections.reverse(tmp);

        for (int i = 0; i < len ; i++) {
            sum += Integer.parseInt(tmp.get(tmp.size() - 1 - i)) * SECONDS[len - 1 - i];
        }

        System.out.printf("=== %d seconds ===\n",sum);

    }
}
