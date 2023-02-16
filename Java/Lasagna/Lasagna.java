public class Lasagna {
    private final int COOKING_TIME_IN_MINS = 40;
  private final int MINS_PREP_PER_LAYER = 2;
  // TODO: define the 'expectedMinutesInOven()' method
 public int expectedMinutesInOven(){
      return COOKING_TIME_IN_MINS;        
  }
  // TODO: define the 'remainingMinutesInOven()' method
  public int remainingMinutesInOven(int minutesPassed){
      return this.expectedMinutesInOven() - minutesPassed;
  }
  // TODO: define the 'preparationTimeInMinutes()' method
public int preparationTimeInMinutes(int numLayers){
      return MINS_PREP_PER_LAYER * numLayers;
  }
  // TODO: define the 'totalTimeInMinutes()' method
  public int totalTimeInMinutes(int numLayers, int minutesPassed){
      return this.preparationTimeInMinutes(numLayers) + minutesPassed;
  }
}
