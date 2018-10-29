/**
 * main.java
 * @author Jake Runyan
 * https://github.com/runyanjake/CodingPractice/Java/JScreen/JScreen.java
 * @desc Screen whose "bits" can be set by specifying 1-indexed coordinate pairs.
 * @note Coordinate system begins at top left, with vertical y axis, horizontal x axis.
 */

package JScreen;

import java.util.ArrayList;

public class JScreen { 
    private double xdim;
    private double ydim;
    private ArrayList<ArrayList<Boolean>> data;
    public JScreen(int xSize, int ySize){
        xdim = xSize;
        ydim = ySize;
        data = new ArrayList<ArrayList<Boolean>>();
        for(int a=0;a<ySize;++a){
            ArrayList<Boolean> tmp = new ArrayList<Boolean>();
            for(int b=0;b<xSize;++b){
                tmp.add(false);
            }
            data.add(tmp);
        }
    }

    public void swapBit(int x, int y){
        if(x > xdim || x <= 0)
            throw new IndexOutOfBoundsException("X dimension " + x + " is out of range.");
        else if(y > ydim || y <= 0)
            throw new IndexOutOfBoundsException("Y dimension " + y + " is out of range.");
        int adjx = x-1, adjy = y-1;
        data.get(adjy).set(adjx, !data.get(adjy).get(adjx));
    }

    public void setMap(ArrayList<ArrayList<Boolean>> bmp){
        if(bmp.size() != ydim || bmp.get(0).size() != xdim)
            throw new IndexOutOfBoundsException("Bitmap input was mis-sized.");
        for(int a=0;a<bmp.size();++a){
            for(int b=0; b<bmp.get(a).size();++b){
                data.get(a).set(b, !bmp.get(a).get(b));
            }
        }
    }

    public void playGOL(){
        boolean changed = true;
        double turns = 0;
        System.out.println("Beginning GOL State:");
        System.out.println(toString());
        while(changed){
            // System.out.println("Taking GOL turn...");
            changed = false;
            ArrayList<ArrayList<Boolean>> frame = new ArrayList<ArrayList<Boolean>>();
            for(int a=0;a<ydim;++a) frame.add(new ArrayList<Boolean>());
            for(int a=0;a<ydim;++a){
                for(int b=0;b<xdim;++b){
                    int liveNeighbors = 0;
                    if(data.get(a).get(b) == true){
                        if(a-1 >= 0 && b-1 >= 0 && data.get(a-1).get(b-1) == true) ++liveNeighbors;
                        if(a-1 >= 0 && data.get(a-1).get(b) == true) ++liveNeighbors;
                        if(a-1 >= 0 && b+1 < xdim && data.get(a-1).get(b+1) == true) ++liveNeighbors;
                        if(b-1 >= 0 && data.get(a).get(b-1) == true) ++liveNeighbors;
                        if(b+1 < xdim && b-1 >= 0 && data.get(a).get(b+1) == true) ++liveNeighbors;
                        if(a+1 < ydim && b-1 >= 0 && data.get(a+1).get(b-1) == true) ++liveNeighbors;
                        if(a+1 < ydim && data.get(a+1).get(b) == true) ++liveNeighbors;
                        if(a+1 < ydim && b+1 < xdim && data.get(a+1).get(b+1) == true) ++liveNeighbors;
                        if(liveNeighbors < 2){
                            frame.get(a).add(false);
                            // System.out.println("Cell " + b + "," + a + " died.");
                            if(!changed)
                                changed = true;
                        }else if(liveNeighbors > 3){
                            frame.get(a).add(false);
                            // System.out.println("Cell " + b + "," + a + " died.");
                            if(!changed)
                                changed = true;
                        }else{ //Stays the same
                            frame.get(a).add(data.get(a).get(b));
                        }
                    }else{
                        if(a-1 >= 0 && b-1 >= 0 && data.get(a-1).get(b-1) == true) ++liveNeighbors;
                        if(a-1 >= 0 && data.get(a-1).get(b) == true) ++liveNeighbors;
                        if(a-1 >= 0 && b+1 < xdim && data.get(a-1).get(b+1) == true) ++liveNeighbors;
                        if(b-1 >= 0 && data.get(a).get(b-1) == true) ++liveNeighbors;
                        if(b+1 < xdim && b-1 >= 0 && data.get(a).get(b+1) == true) ++liveNeighbors;
                        if(a+1 < ydim && b-1 >= 0 && data.get(a+1).get(b-1) == true) ++liveNeighbors;
                        if(a+1 < ydim && data.get(a+1).get(b) == true) ++liveNeighbors;
                        if(a+1 < ydim && b+1 < xdim && data.get(a+1).get(b+1) == true) ++liveNeighbors;
                        if(liveNeighbors == 3){
                            frame.get(a).add(true);
                            // System.out.println("Cell " + b + "," + a + " was birthed.");
                            if(!changed)
                                changed = true;
                        }else{ //Stays the same
                            frame.get(a).add(data.get(a).get(b));
                        }
                    }
                }
            }
            data = frame;
            ++turns;
            System.out.println(toString());
        }
        System.out.println("Game of Life ended after " + turns + " turns.");
    }

    public String toString(){
        String str = "";
        for(int a=0;a<ydim;++a){
            str += "[";
            for(int b=0;b<xdim;++b){
                if(data.get(a).get(b) == true)
                    str += "o";
                else
                    str += " ";
            }
            str += "]\n";
        }
        return str;
    }
}
