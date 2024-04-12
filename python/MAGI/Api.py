import requests

class Api:
    def __init__(self):
        self.base_url = 'https://api.noisr.pt'
        
    def __repr__(self) -> str:
        if self.__get(''):
            return f'Connected to {self.base_url}'
        else:
            return f'Failed to connect to {self.base_url}'
      
    def __get(self, endpoint, params=None):
        """Send a GET request to the specified endpoint."""
        response = requests.get(f'{self.base_url}/{endpoint}', params=params)
        response.raise_for_status()  # Raise an exception if the request failed
        return response

    def __post(self, endpoint, data=None, headers=None):
        """Send a POST request to the specified endpoint."""
        response = requests.post(f'{self.base_url}/{endpoint}', json=data, headers=headers)
        response.raise_for_status()  # Raise an exception if the request failed
        return response
      
    def generate(self, count) -> list:
        """Get a list of random numbers from the API."""
        try:
            response = self.__post('generate', {"count": count}, headers={'Content-Type': 'application/json'})
            # Convert binary numbers to decimal
            return response.json()
        except requests.HTTPError:
            print('HTTP error occurred while getting numbers')
        except requests.ConnectionError:
            print('A network problem occurred')
        except requests.Timeout:
            print('The request timed out')
        except Exception as e:
            print(f'An unexpected error occurred: {e}')