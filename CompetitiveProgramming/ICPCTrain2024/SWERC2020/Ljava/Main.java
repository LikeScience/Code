//import java.io.BufferedReader;
//import java.io.InputStreamReader;
//import java.util.StringTokenizer;
//import java.io.IOException;
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        /*BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        System.out.println(n + "" + m);*/
        Scanner sc = new Scanner (System.in);
        int n = sc.nextInt(), m = sc.nextInt();
        ArrayList<Integer> c = new ArrayList<>(); 
        for (int i = 0; i<m; i++) c.add(sc.nextInt());
        ArrayList<ArrayList<Integer>> a = new ArrayList<>(), b = new ArrayList<>();
        for (int i = 0; i<n; i++) a.add(new ArrayList<Integer>());
        for (int i = 0; i<m; i++) b.add(new ArrayList<Integer>());
        sc.nextLine();
        for (int i = 0; i<n; i++) {
            Scanner sc1 = new Scanner(sc.nextLine());
            while (sc1.hasNextInt()) a.get(i).add(sc1.nextInt()-1); 
        }
        for (int i = 0; i<m; i++) {
            Scanner sc1 = new Scanner(sc.nextLine());
            while (sc1.hasNextInt()) b.get(i).add(sc1.nextInt()-1); 
        }
        /*for (int i = 0; i<n; i++) {
            for (int j = 0; j< a.get(i).size(); j++) {
                System.out.print(a.get(i).get(j) + " ");
            } System.out.print('\n');
        }*/
        ArrayList<TreeMap<Integer, Boolean> > t = new ArrayList<>(), u = new ArrayList<>();
        for (int i = 0; i<n; i++) t.add(new TreeMap<>());
        for (int i = 0; i<m; i++) u.add(new TreeMap<>()); 
        ArrayList<Integer> d = new ArrayList<>(), e = new ArrayList<>();
        for (int i = 0; i<n; i++) d.add(0);
        for (int i = 0; i<m; i++) e.add(0);
        int cnt1 = 0, cnt2 = 0, j = 0;
        ArrayList<Integer> outp = new ArrayList<>();
        while (cnt1 < n && cnt2 < m) {
            for (Integer i = 0; i< n; i++) {
                
                if (j == a.get(i).size()) {
                    cnt1++;
                    continue;
                } else if (j < a.get(i).size() && d.get(i) == 0 && e.get(a.get(i).get(j)) < c.get(a.get(i).get(j))) {
                    t.get(i).put(a.get(i).get(j), true);
                    if (u.get(a.get(i).get(j)).get(i) != null) {
                        
                        outp.add(i);
                        d.set(i,1);
                        e.set(a.get(i).get(j), e.get(a.get(i).get(j))+1);
                    }
                }
            }
            for (Integer i = 0; i< m; i++) {
                if (j == b.get(i).size()) {
                    cnt2++;
                } else if (j < b.get(i).size() && d.get(b.get(i).get(j)) ==0 && e.get(i) < c.get(i)) {
                    u.get(i).put(b.get(i).get(j), true);
                    if (t.get(b.get(i).get(j)).get(i)!= null) {
                        
                        outp.add(b.get(i).get(j));
                        d.set(b.get(i).get(j), 1);
                        e.set(i, e.get(i)+1);
                    }
                }
            }
            j++;
        }
        Collections.sort(outp);
        for (Integer x : outp) {
            System.out.println(x+1);
        }
    }
    
}
